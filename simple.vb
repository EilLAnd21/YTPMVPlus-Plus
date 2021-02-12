
	void parseOptions(int argc, char** argv) {
		int opt;
		while ((opt = getopt(argc, argv, "vq")) != -1) {
		while ((opt = getopt(argc, argv, "vqs:")) != -1) {
			if(opt == 'v') verbosity = 1;
			else if(opt == 'q') verbosity = -1;
			else goto print_usage;
			else if(opt == 's') {
				defaultSettings.skipToSeconds = atof(optarg);
			} else goto print_usage;
		}
		if(optind < argc) {
			if(strcmp(argv[optind], "play") == 0) {
