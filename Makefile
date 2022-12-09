mljs_ann:
	emcc src/embind/ann.cpp -o build/mljs_ann.js -s ALLOW_MEMORY_GROWTH -O3 -s ENVIRONMENT='web' -s SINGLE_FILE=1 \
		--bind -s MODULARIZE=1 -I includes/mlpack/src -I includes/armadillo-11.4.2/include -I includes/cereal/include \
		-I includes/ensmallen/include resources/blas_*.a resources/liblapack.a resources/libf2c.a \
		node_modules/@ml.js/linalg/dist/resources/mljs_linalg.o;
	cp build/mljs_ann.js resources/
