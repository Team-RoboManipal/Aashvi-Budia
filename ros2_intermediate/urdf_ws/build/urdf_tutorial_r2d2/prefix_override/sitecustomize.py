import sys
if sys.prefix == '/Users/aashvibudia/miniconda3/envs/ros_humble':
    sys.real_prefix = sys.prefix
    sys.prefix = sys.exec_prefix = '/Users/aashvibudia/urdf_ws/install/urdf_tutorial_r2d2'
