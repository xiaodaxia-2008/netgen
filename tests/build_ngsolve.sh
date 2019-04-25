cd ~/src
git clone https://github.com/NGSolve/ngsolve.git
mkdir -p ~/build/ngsolve
cd ~/build/ngsolve
cmake \
  -DUSE_MKL=ON \
  -DUSE_CCACHE=ON \
  -DNETGEN_DIR=/opt/netgen \
  -DCMAKE_BUILD_TYPE=RelWithDebInfo \
  ~/src/ngsolve
make -j12
make install
