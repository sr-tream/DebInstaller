# CMake generated Testfile for 
# Source directory: /home/sr-tream/Projects/workspace/DebInstaller
# Build directory: /home/sr-tream/Projects/workspace/DebInstaller/build
# 
# This file includes the relevant testing commands required for 
# testing this directory and lists subdirectories to be tested as well.
add_test(appstreamtest "/usr/bin/cmake" "-DAPPSTREAMCLI=/usr/bin/appstreamcli" "-DINSTALL_FILES=/home/sr-tream/Projects/workspace/DebInstaller/build/install_manifest.txt" "-P" "/usr/share/ECM/kde-modules/appstreamtest.cmake")
subdirs("src")
