# libconfigdemo
A Simple C Program Demonstrating libconfig Usage
## Credits/Authors
[Jan-Piet Mens](https://jpmens.net/)
This demo program has been written by:	Jan-Piet Mens and originally  published in an article linked below. I am copying the code here, along with author's name and URL just to increase discoverability to assist others to find/clone this demo code.
* Original URL: https://jpmens.net/2009/09/17/reading-configuration-files-with-libconfig
* Backup URL at archive.org: https://web.archive.org/web/20180203004726/https://jpmens.net/2009/09/17/reading-configuration-files-with-libconfig
## Prerequisites
Demo code requires the libconfig package of course - no other dependencies.
###libconfig - MAC OS X homebrew package manager installation: `brew install libconfig`
###*NIX compilation & installation from sources: 

    wget https://hyperrealm.github.io/libconfig/dist/libconfig-1.7.2.tar.gz
    tar xfvz libconfig-1.7.2.tar.gz
    cd libconfig-1.7.2
    ./configure
    make
    sudo make install
## Compilation
Compiled & tested with: `clang -x c -std=c89 -pedantic-errors -Wall -Werror -Wextra -Wcomment -Wparentheses -Wformat-zero-length -lconfig libconfigdemo.c -o libconfigdemo`
## Contributing
Any pull requests (bugfix, improvement) are more than welcome!
## License
GNU GPL v3 License - see the [LICENSE](LICENSE) file for details.
