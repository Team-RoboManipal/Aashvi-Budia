from setuptools import find_packages, setup

package_name = 'polygon_pkg'

setup(
    name=package_name,
    version='0.0.0',
    packages=find_packages(exclude=['test']),
    data_files=[
        ('share/ament_index/resource_index/packages', ['resource/' + package_name]),
        ('share/' + package_name, ['package.xml']),
    ],
    install_requires=['setuptools'],
    zip_safe=True,
    maintainer='aashvi',
    maintainer_email='aashvi@todo.todo',
    description='ROS2 service for drawing polygons using turtlesim',
    license='Apache-2.0',
    tests_require=['pytest'],
    entry_points={
        'console_scripts': [
            'draw_polygon_server=polygon_pkg.service_member_function:main',
            'polygon_client =polygon_pkg.polygon_client:main',
        ],
    },
)
