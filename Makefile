run:
	# npm install -g http-server
	rm -f arithmeticWS.html arithmeticWS.js arithmeticWS.wasm
	emcc arithmeticWS.c -s WASM=1 -o arithmeticWS.html
	http-server

clean:
	rm -f arithmeticWS.html arithmeticWS.js arithmeticWS.wasm
	