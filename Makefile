lab1:
	cmake lab1/
	cmake --build lab1/build/
	./lab1/build/lab_tests

clean:
	rm -r -f lab1/build/