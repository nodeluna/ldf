#ifndef ABOUT
#define ABOUT

#include <string>

namespace about{
	inline std::string author = 
		" -> nodeluna - nodeluna@proton.me\n"
		" -> https://github.com/nodeluna\n";

	inline std::string version = "--> ldf 0.2.6";

	inline std::string license = 
		"--> GPLv3\n"
		"--> This program is distributed in the hope that it will be useful, \n"
		"	but WITHOUT ANY WARRANTY; without even the implied warranty of MERCHANTABILITY or FITNESS FOR \n"
		"	A PARTICULAR PURPOSE. See the GNU General Public License version 3 for more details.\n"
		" -> https://www.gnu.org/licenses/gpl-3.0.en.html\n";

	inline std::string help =">>> report filesystem space info of devices and RAM/swap usage\n"
		"        _      _    __\n"
		"       | |  __| |  / _|\n"
		"       | | / _` | |  _|\n"
		"       |_| \\__,_| |_|\n"
		"\n"
		"  usage\n"
		"	ldf\n"
		"	ldf --ram off --swap off\n"
		"\n"
		"  options\n"
		"    [--devices, -d] <on/off>\n"
		"        print devices info. empty argument is consideren 'on'. default is 'on'\n"
		"\n"
		"    [--ram, -r] <on/off>\n"
		"        print ram info. empty argument is consideren 'on'. default is 'on'\n"
		"\n"
		"    [--swap, -s] <on/off>\n"
		"        print swap info. empty argument is consideren 'on'. default is 'on'\n"
		"\n"
		"    [--author]\n"
		"        print the program's author\n"
		"\n"
		"    [--license]\n"
		"        print the program's license\n"
		"\n"
		"    [-V, --version]\n"
		"        print the program's version\n"
		"\n"
		"    [--help]\n"
		"        print this help statement\n";
}

#endif // ABOUT
