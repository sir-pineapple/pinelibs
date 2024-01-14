clean:
	@printf "Removing residuals...."
	@rm *.o -r lib
	@printf "Done\n"

uninstall: /usr/include/pinelibs.h /usr/lib/libpine*
	@printf "Deleting header files...."
	@sudo rm /usr/include/pinelibs.h -rf /usr/include/pinelibs/
	@printf "Done\n"
	@printf "Deleting lib files...."
	@sudo rm /usr/lib/libpine*
	@printf "Done\n"

install:
	make headers
	make libs

headers:
	@printf "Installing header files...."
	@sudo cp -r include/* /usr/include
	@printf "Done\n"

libs: /usr/include/pinelibs.h
	@mkdir lib
	@printf "Compiling libraries...."
	@gcc -c src/*
	@ar rcs lib/libpinefloat.a float.o
	@ar rcs lib/libpinevector.a vector.o
	@ar rcs lib/libpinell.a linkedlist.o
	@ar rcs lib/libpinestack.a stack.o
	@ar rcs lib/libpinequeue.a queue.o
	@ar rcs lib/libpinetree.a tree.o
	@rm *.o
	@printf "Done\n"
	@printf "Installing libraries...."
	@sudo mv lib/* /usr/lib
	@rm -r lib
	@printf "Done\n"
