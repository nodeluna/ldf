CC = g++
CFLAGS = -O1 -Iinclude -Wall -Wextra -pedantic -std=c++20
TARGET = ldf
PREFIX = /usr
INSTALL_DIR = $(PREFIX)/bin
BUILD_DIR = build
HEADER_DIR = include
MANPAGE_DIR = $(PREFIX)/share/man/man1
SRC_DIR = src
SRCS := $(wildcard src/*.cpp)
HEADERS := $(wildcard include/*.h)
OBJS := $(addprefix build/, $(notdir $(SRCS:.cpp=.o)))
DEP := $(OBJS:.o=.d)


ifneq ($(findstring clang++, $(CC)),)
	CFLAGS += -D__cpp_concepts=202002L -Wno-builtin-macro-redefined -Wno-macro-redefined
endif

all: mkdir_build $(OBJS) $(TARGET)

build/%.o: src/%.cpp
	$(CC) $(CFLAGS) -MMD -MP -c $< -o $@

$(TARGET): $(OBJS)
	$(CC) $(CFLAGS) $^ -o $@

install: 
	$(info :: Installing $(TARGET))
	install -Dm755 $(TARGET) $(INSTALL_DIR)/$(TARGET)
	mkdir -p $(INSTALL_DIR) $(MANPAGE_DIR)
	install -Dm644 man/$(TARGET).1 $(MANPAGE_DIR)/

uninstall:
	$(info :: Uninstalling $(TARGET))
	rm $(INSTALL_DIR)/$(TARGET)
	rm $(MANPAGE_DIR)/$(TARGET).1

mkdir_build:
	@for i in $(BUILD_DIR); do\
		if [ ! -f "$$i" ]; then\
			mkdir -p $$i;\
		fi;\
	done

clean:
	$(info :: cleaning build)
	@for i in $(BUILD_DIR) $(TARGET); do\
		if [ -f "$$i" ] || [ -d "$$i" ]; then\
			rm -r "$$i";\
		fi;\
	done

cppcheck: mkdir_build
	$(info :: running static code analysis)
	$(info  )
	cppcheck --cppcheck-build-dir=$(BUILD_DIR) --std=c++20 --check-level=exhaustive --suppress=unreadVariable\
		--suppress=missingIncludeSystem --enable=all -I $(HEADER_DIR) $(SRC_DIR)

format:
	clang-format -i $(SRCS) $(HEADERS)


-include $(DEP)
