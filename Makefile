run:
	# npm install -g http-server
	rm -f arithmetic.html arithmetic.js arithmetic.wasm
	emcc arithmetic.c -s WASM=1 -o arithmetic.html
	http-server

clean:
	rm arithmetic.html arithmetic.js arithmetic.wasm
	