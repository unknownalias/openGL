g++ opengl_test.cpp -o "opengl_test.out" -lglut -lGL -lGLU -std=c++11 -pthread

testret=$?
echo $testret

if [ $testret -eq 0 ]; then
	echo "Build Success"
	chmod +x opengl_test.out
	./opengl_test.out
else
	echo "Build Failure"
fi
