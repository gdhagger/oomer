clean:
	rm -rf dist

mkdist:
	mkdir -p dist

build: clean mkdist
	musl-gcc main.c -o dist/oomer

package:
	docker build -t gdhagger/oomer .

push:
	docker push gdhagger/oomer