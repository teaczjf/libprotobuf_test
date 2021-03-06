export XPL_OBJECT_TYPE="ARM"
export XPL_PROJECT_DIR=$(pwd)
export XPL_FEATURE_DIR=$XPL_PROJECT_DIR/feature
export XPL_PROTOCOL_DIR=$XPL_PROJECT_DIR/protocol
export XPL_THIRDPARTY_DIR=$XPL_PROJECT_DIR/thirdparty
export CCACHE_PATH=/usr/bin:$CCACHE_PATH
export CC="arm-linux-gnueabihf-gcc"
export CXX="arm-linux-gnueabihf-g++"
export AR="gcc-ar"
export CPP="gcc"
export AS="as"
export GDB=gdb
export STRIP=strip
export RANLIB=ranlib
export OBJCOPY=objcopy
export OBJDUMP=objdump
export PATH=/opt/gcc-linaro-arm-linux-gnueabihf-4.9-2014.09_linux/bin:$PATH


