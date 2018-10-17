cd ../STUDENT&&make
cd ../LESSON&&make
ar -rsv ../RELEASE/libmain.a ../RELEASE/stu.o ../RELEASE/less.o
cd ../MAIN&&make
cd ../RELEASE;./main
