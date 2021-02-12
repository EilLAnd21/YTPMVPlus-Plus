#YTPMVPLUS=mp3parser.C audiorenderer.C videoclipcache.C mmutil.C framerenderer.C videorenderer.C simple.C -lGL -lGLEW -lEGL -lX11 -lgbm -lSoundTouch -lpthread -lasound `pkg-config --cflags --libs gstreamer-1.0 gio-2.0`

LIBYTPMV=common.o glutil.o texturecache.o modparser.o audiorenderer.o samplecache.o mmutil.o framerenderer.o framerenderer2.o videorenderer.o simple.o
LIBYTPMV=common.o glutil.o texturecache.o modparser.o audiorenderer.o samplecache.o mmutil.o framerenderer2.o videorenderer.o simple.o
LIBS= -lglfw -lGL -lGLEW -lEGL -lX11 -lgbm -lSoundTouch -lpthread -lasound `pkg-config --libs gstreamer-1.0 gio-2.0`

CFLAGS ?= -O2

	};
	void renderRegion(ActiveNote* notes, int noteCount, int curTimeSamples,
						int durationSamples, int srate, float* outBuf) {
		double f = 50./srate;
		for(int i=0;i<durationSamples;i++) {
			int t = i + curTimeSamples;
			float curSample[CHANNELS] = {};
@@ -75,11 +74,12 @@ namespace ytpmv {
		SampleCache cache;

		// pre-populate sample cache with all used samples and pitches
		PRNT(0, "populating pitch shift cache...\n");
		for(const AudioSegment& s: segments) {
			double relativePitch = s.pitch/s.tempo;
			cache.getPitchShiftedSample(s.sampleData, s.sampleLength, relativePitch);
		}
		fprintf(stderr, "sample cache populated; %d samples\n", (int)cache.entries.size());
		PRNT(0, "sample cache populated; %d samples\n", (int)cache.entries.size());

		// convert note list into note event list
		vector<NoteEvent> events;
@@ -112,10 +112,10 @@ namespace ytpmv {
			if(!evt.off) { // note on
				notesActive[evt.segmentIndex] = curTimeSamples;
				const AudioSegment& s = segments.at(evt.segmentIndex);
				fprintf(stderr, "note on: %5d:  pitch %5.2f  vol %3.1f  dur %3.2fs\n", evt.segmentIndex, s.pitch,s.amplitude[0], s.durationSeconds());
				PRNT(1, "note on: %5d:  pitch %5.2f  vol %3.1f  dur %3.2fs\n", evt.segmentIndex, s.pitch,s.amplitude[0], s.durationSeconds());
			} else {
				notesActive.erase(evt.segmentIndex);
				fprintf(stderr, "note off:%5d\n", evt.segmentIndex);
				PRNT(1, "note off:%5d\n", evt.segmentIndex);
			}

			// calculate time until next event

		int InfoLogLength;

		// Compile Vertex Shader
		fprintf(stderr, "Compiling vertex shader\n");
		PRNT(0, "Compiling vertex shader\n");
		char const * VertexSourcePointer = VertexShaderCode.c_str();
		glShaderSource(VertexShaderID, 1, &VertexSourcePointer , NULL);
		glCompileShader(VertexShaderID);
@@ -62,11 +62,11 @@ namespace ytpmv {
		if ( InfoLogLength > 0 ){
			std::vector<char> VertexShaderErrorMessage(InfoLogLength+1);
			glGetShaderInfoLog(VertexShaderID, InfoLogLength, NULL, &VertexShaderErrorMessage[0]);
			fprintf(stderr, "%s\n", &VertexShaderErrorMessage[0]);
			PRNT(0, "%s\n", &VertexShaderErrorMessage[0]);
		}

		// Compile Fragment Shader
		fprintf(stderr, "Compiling fragment shader\n");
		PRNT(0, "Compiling fragment shader\n");
		char const * FragmentSourcePointer = FragmentShaderCode.c_str();
		glShaderSource(FragmentShaderID, 1, &FragmentSourcePointer , NULL);
		glCompileShader(FragmentShaderID);
@@ -77,11 +77,11 @@ namespace ytpmv {
		if ( InfoLogLength > 0 ){
			std::vector<char> FragmentShaderErrorMessage(InfoLogLength+1);
			glGetShaderInfoLog(FragmentShaderID, InfoLogLength, NULL, &FragmentShaderErrorMessage[0]);
			fprintf(stderr, "%s\n", &FragmentShaderErrorMessage[0]);
			PRNT(0, "%s\n", &FragmentShaderErrorMessage[0]);
		}

		// Link the program
		fprintf(stderr, "Linking program\n");
		PRNT(0, "Linking program\n");
		GLuint ProgramID = glCreateProgram();
		glAttachShader(ProgramID, VertexShaderID);
		glAttachShader(ProgramID, FragmentShaderID);
@@ -93,7 +93,7 @@ namespace ytpmv {
		if ( InfoLogLength > 0 ){
			std::vector<char> ProgramErrorMessage(InfoLogLength+1);
			glGetProgramInfoLog(ProgramID, InfoLogLength, NULL, &ProgramErrorMessage[0]);
			fprintf(stderr, "%s\n", &ProgramErrorMessage[0]);
			PRNT(0, "%s\n", &ProgramErrorMessage[0]);
		}
		glDetachShader(ProgramID, VertexShaderID);
		glDetachShader(ProgramID, FragmentShaderID);
@@ -151,7 +151,7 @@ namespace ytpmv {
		glBufferData(GL_ARRAY_BUFFER, sizeof(g_vertex_buffer_data), g_vertex_buffer_data, GL_STATIC_DRAW);

		glGetIntegerv(GL_MAX_COMBINED_TEXTURE_IMAGE_UNITS, &textureUnits);
		fprintf(stderr, "number of texture units: %d\n", textureUnits);
		PRNT(0, "number of texture units: %d\n", textureUnits);
		textureUnitContents.resize(textureUnits);
	}
	string FrameRenderer2_generateCode(string code, int maxParams) {
@@ -304,12 +304,12 @@ namespace ytpmv {
				totalVarSize += varSizes[varIndex];
			int nVertex = int(vert.size()) / totalVarSize;

			//fprintf(stderr, "nVertex %d\n", nVertex);
			//PRNT(0, "nVertex %d\n", nVertex);

			int varOffs = vertexOffs;
			for(int varIndex=0; varSizes[varIndex] != 0; varIndex++) {
				int varSize = varSizes[varIndex];
				//fprintf(stderr, "glVertexAttribPointer %d %d %d\n", varIndex, varSize, varOffs);
				//PRNT(0, "glVertexAttribPointer %d %d %d\n", varIndex, varSize, varOffs);
				glVertexAttribPointer(
				   varIndex,           // variable id. must match the "layout" of the variable in the shader.
				   varSize,            // number of elements per vertex
@@ -361,7 +361,7 @@ namespace ytpmv {
		glReadPixels(0,0,w,h,  GL_RGBA,  GL_UNSIGNED_INT_8_8_8_8_REV, (void*)ret.data());

		assert(glGetError()==GL_NO_ERROR);
		//fprintf(stderr, "%d\n", (int)glGetError());
		//PRNT(0, "%d\n", (int)glGetError());
		return ret;
	}
	void FrameRenderer2::setRenderToScreen() {
  
  	// 1: verbose
	extern int verbosity;

	#define PRNT(minVerbosity, ...) if(verbosity >= minVerbosity) { fprintf(stderr, __VA_ARGS__); }

	template<class T> T clamp(T val, T min, T max) {
		if(val < min) val = min;
		if(val > max) val = max;

            //                "SAMPLE_BUFFERS = %d, SAMPLES = %d",
            //                 i, vi -> visualid, samp_buf, samples);

            if (best_fbc < 0 || videoclip_buf && videoclip > best_num_samp) {
            if (best_fbc < 0 || (videoclip_buf && videoclip > best_num_samp)) {
                best_fbc = i, best_num_samp = samples;
            }

@@ -172,7 +172,7 @@ void createGLContext()

    // Get a visual
    XVisualInfo *vi = glXGetVisualFromFBConfig(display, bestFbc);
    MSG("Chosen visual ID = 0x%x", vi->visualid);
    MSG("Chosen visual ID = 0x%lx", vi->visualid);

    MSG("Creating colormap");
    XSetWindowAttributes swa;
    
    		basic_string<float>& getPitchShiftedSample(const float* sampleData, int sampleLen, double pitch);
	};

	static bool operator<(const MP4VideoCache::Key& k1, const MP4VideoCache::Key& k2) {
		if(k1.data < k2.data) return true;
		if(k1.data > k2.data) return false;
		return k1.pitch < k2.pitch;
	}
	bool operator<(const SampleCache::Key& k1, const SampleCache::Key& k2);
}

		else if (nano == 2) nano_str = "(Prerelease)";
		else nano_str = "";

		fprintf (stderr, "This program is linked against GStreamer %d.%d.%d %s\n",
		PRNT(0, "This program is linked against GStreamer %d.%d.%d %s\n",
				major, minor, micro, nano_str);
		return 0;
	}
@@ -34,7 +34,7 @@ namespace ytpmv {
							 GstPad *pad,
							 gpointer data) {
		GstElement *convert = (GstElement *) data;
		fprintf(stderr, "pad added\n");
		PRNT(1, "pad added\n");
		GstCaps *caps;
		GstStructure *str;
		GstPad *audiopad;
@@ -47,17 +47,17 @@ namespace ytpmv {

		caps = gst_pad_query_caps(pad, NULL);
		str = gst_caps_get_structure(caps, 0);
		fprintf(stderr, "here %s\n",gst_structure_get_name(str));
		PRNT(1, "here %s\n",gst_structure_get_name(str));
		if (!g_strrstr(gst_structure_get_name(str), "audio")) {
			gst_caps_unref(caps);
			gst_object_unref(audiopad);
			fprintf(stderr, "ERROR 1\n");
			PRNT(1, "not audio pad\n");
			return;
		}
		gst_caps_unref(caps);
		gst_pad_link(pad, audiopad);
		g_object_unref(audiopad);
		fprintf(stderr, "pad linked\n");
		PRNT(1, "pad linked\n");
	}

	static gboolean bus_call(GstBus *bus,
@@ -67,7 +67,7 @@ namespace ytpmv {

		switch (GST_MESSAGE_TYPE(msg)) {
			case GST_MESSAGE_EOS:
				fprintf(stderr, "End of stream\n");
				PRNT(1, "End of stream\n");
				g_main_loop_quit(loop);
				break;
			case GST_MESSAGE_ERROR: {
@@ -95,7 +95,6 @@ namespace ytpmv {
	// TODO(xaxaxa): set AudioSource speed based on systemSRate and file srate
	AudioSource* loadAudio(const char* file, int systemSRate) {
		GstElement *pipeline, *source, *decode, *sink, *convert;
		int rate = systemSRate;
		int channels = CHANNELS;
		GMainLoop *loop;
		GstBus *bus;
@@ -145,26 +144,26 @@ namespace ytpmv {
		gst_element_set_state(GST_ELEMENT(pipeline), GST_STATE_PLAYING);

		// iterate
		fprintf(stderr, "RUNNING GSTREAMER PIPELINE FOR AUDIO: %s\n", file);
		PRNT(0, "RUNNING GSTREAMER PIPELINE FOR AUDIO: %s\n", file);
		g_main_loop_run(loop);

		// out of the main loop, clean up nicely
		fprintf(stderr, "Returned, stopping playback\n");
		PRNT(0, "Returned, stopping playback\n");
		gst_element_set_state(pipeline, GST_STATE_NULL);

		fprintf(stderr, "Deleting pipeline\n");
		PRNT(1, "Deleting pipeline\n");
		gst_object_unref(GST_OBJECT(pipeline));
		g_source_remove (bus_watch_id);
		g_main_loop_unref(loop);

		// get data
		fprintf(stderr, "get data\n");
		PRNT(1, "get data\n");
		out_data = g_memory_output_stream_get_data(G_MEMORY_OUTPUT_STREAM(stream));

		unsigned long size = g_memory_output_stream_get_size(G_MEMORY_OUTPUT_STREAM(stream));
		unsigned long sizeData = g_memory_output_stream_get_data_size(G_MEMORY_OUTPUT_STREAM(stream));
		std::cerr << "stream size: " << size << std::endl;
		std::cerr << "stream data size: " << sizeData << std::endl;
		PRNT(1, "stream size: %lu\n", size);
		PRNT(1, "stream data size: %lu\n", sizeData);

		// access data and store in vector
		AudioSource* as = new AudioSource();
@@ -175,7 +174,7 @@ namespace ytpmv {
		as->sample.resize(sizeData/2);
		for (unsigned long i = 0; i < sizeData/2; ++i) {
			as->sample[i] = float(((int16_t*)out_data)[i])*scale;
			//fprintf(stderr, "%d\n", int(((int16_t*)out_data)[i]));
			//PRNT(0, "%d\n", int(((int16_t*)out_data)[i]));
		}
		return as;
	}
@@ -184,7 +183,7 @@ namespace ytpmv {
							 GstPad *pad,
							 gpointer data) {
		GstElement *convert = (GstElement *) data;
		fprintf(stderr, "pad added\n");
		PRNT(1, "pad added\n");
		GstCaps *caps;
		GstStructure *str;
		GstPad *videopad;
@@ -197,18 +196,18 @@ namespace ytpmv {

		caps = gst_pad_query_caps(pad, NULL);
		str = gst_caps_get_structure(caps, 0);
		fprintf(stderr, "here %s\n",gst_structure_get_name(str));
		PRNT(1, "here %s\n",gst_structure_get_name(str));
		if (!g_strrstr(gst_structure_get_name(str), "video")) {
			gst_caps_unref(caps);
			gst_object_unref(videopad);
			fprintf(stderr, "ERROR 1\n");
			PRNT(1, "not video pad\n");
			return;
		}

		gst_caps_unref(caps);
		gst_pad_link(pad, videopad);
		g_object_unref(videopad);
		fprintf(stderr, "pad linked\n");
		PRNT(1, "pad linked\n");
	}

	// TODO(xaxaxa): convert all this code to use gst_parse_launch() instead
@@ -261,27 +260,27 @@ namespace ytpmv {
		gst_element_set_state(GST_ELEMENT(pipeline), GST_STATE_PLAYING);

		// iterate
		fprintf(stderr, "RUNNING GSTREAMER PIPELINE FOR VIDEO: %s\n", file);
		PRNT(0, "RUNNING GSTREAMER PIPELINE FOR VIDEO: %s\n", file);
		g_main_loop_run(loop);


		// retrieve the dimensions of the video
		GstPad* sinkPad = gst_element_get_static_pad (sink, "sink");
		GstCaps* sinkCaps = gst_pad_get_current_caps (sinkPad);
		GstStructure* sinkCapsStruct = gst_caps_get_structure(sinkCaps, 0);
		fprintf(stderr, "pad caps: %s\n",  gst_caps_to_string (sinkCaps));
		PRNT(1, "pad caps: %s\n",  gst_caps_to_string (sinkCaps));

		if((!gst_structure_get_int (sinkCapsStruct, "width", &width))
			|| (!gst_structure_get_int (sinkCapsStruct, "height", &height))) {
			throw runtime_error(string("No Width/Height are Available in the Incoming Stream Data !! file: ") + file + "\n");
		}
		fprintf(stderr, "dimensions: %d x %d\n", width, height);
		PRNT(0, "dimensions: %d x %d\n", width, height);

		// out of the main loop, clean up nicely
		fprintf(stderr, "Returned, stopping playback\n");
		PRNT(0, "Returned, stopping playback\n");
		gst_element_set_state(pipeline, GST_STATE_NULL);

		fprintf(stderr, "Deleting pipeline\n");
		PRNT(1, "Deleting pipeline\n");
		gst_object_unref(GST_OBJECT(pipeline));
		g_source_remove (bus_watch_id);
		g_main_loop_unref(loop);
@@ -293,13 +292,13 @@ namespace ytpmv {
		GMemoryOutputStream *stream = loadVideo(file, width, height);

		// get data
		fprintf(stderr, "get data\n");
		PRNT(1, "get data\n");
		char* out_data = (char*)g_memory_output_stream_get_data(G_MEMORY_OUTPUT_STREAM(stream));

		unsigned long size = g_memory_output_stream_get_size(G_MEMORY_OUTPUT_STREAM(stream));
		unsigned long sizeData = g_memory_output_stream_get_data_size(G_MEMORY_OUTPUT_STREAM(stream));
		std::cerr << "stream size: " << size << std::endl;
		std::cerr << "stream data size: " << sizeData << std::endl;
		PRNT(1, "stream size: %lu\n", size);
		PRNT(1, "stream data size: %lu\n", sizeData);

		// access data and store in vector
		int imgBytes = width*height*3;
@@ -308,10 +307,10 @@ namespace ytpmv {
		vs->name = file;
		vs->fps = 30.;

		for(int i=0; i<sizeData; i+=imgBytes) {
			int bytesLeft = sizeData-i;
			if(bytesLeft < imgBytes) break;
			vs->frames.push_back({width, height, {out_data + i, imgBytes}, 0});
		for(long i=0; i<(long)sizeData; i+=imgBytes) {
			long bytesLeft = sizeData-i;
			if(bytesLeft < long(imgBytes)) break;
			vs->frames.push_back({width, height, string(out_data + i, imgBytes), 0});
		}
		g_object_unref(stream);
		return vs;
@@ -333,7 +332,6 @@ namespace ytpmv {
		GstElement *pipeline, *source, *decode, *sink, *convert;
		GMainLoop *loop;
		GstBus *bus;
		guint bus_watch_id;

		// loop
		loop = g_main_loop_new(NULL, false);
@@ -354,7 +352,7 @@ namespace ytpmv {

		// bus
		bus = gst_pipeline_get_bus(GST_PIPELINE (pipeline));
		bus_watch_id = gst_bus_add_watch(bus, bus_call, loop);
		gst_bus_add_watch(bus, bus_call, loop);
		gst_object_unref(bus);

		// add elements into pipeline
@@ -379,27 +377,27 @@ namespace ytpmv {
		/*GstPad* sinkPad = gst_element_get_static_pad (sink, "sink");
		GstCaps* sinkCaps = gst_pad_get_current_caps (sinkPad);
		GstStructure* sinkCapsStruct = gst_caps_get_structure(sinkCaps, 0);
		fprintf(stderr, "pad caps: %s\n",  gst_caps_to_string (sinkCaps));
		PRNT(0, "pad caps: %s\n",  gst_caps_to_string (sinkCaps));
		
		if((!gst_structure_get_int (sinkCapsStruct, "width", &w))
			|| (!gst_structure_get_int (sinkCapsStruct, "height", &h))) {
			throw runtime_error(string("No Width/Height are Available in the Incoming Stream Data !! file: ") + file + "\n");
		}
		fprintf(stderr, "dimensions: %d x %d\n", w, h);*/
		PRNT(0, "dimensions: %d x %d\n", w, h);*/

		// iterate
		fprintf(stderr, "RUNNING GSTREAMER PIPELINE FOR VIDEO: %s\n", file);
		PRNT(0, "RUNNING GSTREAMER PIPELINE FOR VIDEO: %s\n", file);
		//g_main_loop_run(loop);

		pthread_t pth;
		pthread_create(&pth, nullptr, runLoopThread, loop);

		/*
		// out of the main loop, clean up nicely
		fprintf(stderr, "Returned, stopping playback\n");
		PRNT(0, "Returned, stopping playback\n");
		gst_element_set_state(pipeline, GST_STATE_NULL);
		fprintf(stderr, "Deleting pipeline\n");
		PRNT(0, "Deleting pipeline\n");
		gst_object_unref(GST_OBJECT(pipeline));
		g_source_remove (bus_watch_id);
		g_main_loop_unref(loop);*/
@@ -411,7 +409,7 @@ namespace ytpmv {
					" ! videoconvert ! x264enc bitrate=8192 ! mp4mux fragment-duration=1000 streamable=true name=mux ! fdsink fd=" + to_string(outFD)
					+ " fdsrc name=fdsrc_audio fd=" + to_string(audioFD) + 
					" ! rawaudioparse pcm-format=GST_AUDIO_FORMAT_S16LE num-channels=2 interleaved=true sample-rate="+to_string(srate)+" ! audioconvert ! lamemp3enc ! mux.";
		fprintf(stderr, "%s\n", desc.c_str());
		PRNT(0, "%s\n", desc.c_str());
		GError* err = nullptr;
		GstElement* pipeline = gst_parse_launch(desc.c_str(), &err);
		if(err != nullptr) {
@@ -464,17 +462,17 @@ namespace ytpmv {
		GMemoryOutputStream *stream = loadVideo(file.c_str(), width, height);

		// get data
		fprintf(stderr, "get data\n");
		PRNT(1, "get data\n");
		char* out_data = (char*)g_memory_output_stream_get_data(G_MEMORY_OUTPUT_STREAM(stream));
		unsigned long size = g_memory_output_stream_get_size(G_MEMORY_OUTPUT_STREAM(stream));
		//unsigned long size = g_memory_output_stream_get_size(G_MEMORY_OUTPUT_STREAM(stream));
		unsigned long sizeData = g_memory_output_stream_get_data_size(G_MEMORY_OUTPUT_STREAM(stream));

		int stride = (width*3 + 3)/4*4;
		int imgBytes = stride*height;

		for(int i=0; i<sizeData; i+=imgBytes) {
			int bytesLeft = sizeData-i;
			if(bytesLeft < imgBytes) break;
		for(long i=0; i<(long)sizeData; i+=imgBytes) {
			long bytesLeft = sizeData-i;
			if(bytesLeft < (long)imgBytes) break;
			uint32_t tex = createTexture();
			setTextureImage(tex, out_data+i, width, height);
			frames.push_back(tex);
	static string getString(const void* data, int maxLen) {
		string tmp((char*)data, maxLen);
		int l = strlen((char*)data);
		if(l < tmp.length())
		if(l < int(tmp.length()))
			tmp.resize(l);
		return tmp;
	}
@@ -78,7 +78,7 @@ namespace ytpmv {
							tickDuration = 2.5/double(effect&0xff);
						}
						ps.bpm = 60./(ticksPerRow*tickDuration);
						fprintf(stderr, "%d, %d, %x: bpm %f\n", row, channel, effect, ps.bpm);
						PRNT(0, "row %d, channel %d, effect %x: bpm %f\n", row, channel, effect, ps.bpm);
					}
				}
				// if an instrument is specified without a note, start a new note with the last pitch
@@ -115,7 +115,7 @@ namespace ytpmv {
						// set volume
						if((effect & 0xF00) == 0xC00) {
							double dB = log10(double(effect&0xff)/64.)*20;
							n.keyframes.push_back({ps.curRowAbs-n.start.absRow, dB-n.amplitudeDB, 0.});
							n.keyframes.push_back({double(ps.curRowAbs-n.start.absRow), dB-n.amplitudeDB, 0.});
							//fprintf(stderr, "KEYFRAME: %f\n", dB);
						}
					}
@@ -232,7 +232,6 @@ namespace ytpmv {
		ps.defaultVolumes = defaultVolumes;
		for(int i=0; i<songLength; i++) {
			int pattern = seqTable[i];
			fprintf(stderr, "%d\n", pattern);
			const uint8_t* patternData = inData + 1084 + patternBytes*pattern;
			parseModPattern(patternData, patternRows, ps);

@@ -243,8 +242,6 @@ namespace ytpmv {

		int sampleStart = 1084+patternBytes*nPatterns;

		fprintf(stderr, "%d %d\n", inLen, sampleStart);

		// load samples
		for(int i=0;i<31;i++) {
			Instrument& ins = outInstruments[i];
      @@ -40,4 +40,9 @@ namespace ytpmv {
		}
		return ret;
	}
	bool operator<(const SampleCache::Key& k1, const SampleCache::Key& k2) {
		if(k1.data < k2.data) return true;
		if(k1.data > k2.data) return false;
		return k1.pitch < k2.pitch;
	}
  
  					frame = (int)round(double(t)*1e-6*fps);
				}

				//fprintf(stderr, "ADVANCE TO FRAME %d\n", frame);
				//PRNT(0, "ADVANCE TO FRAME %d\n", frame);
				if(!videoRenderer->advanceTo(frame)) break;

				uint64_t micros1 = getTimeMicros();
@@ -189,7 +189,7 @@ namespace ytpmv {
				renderDelay = getTimeMicros() - micros1;

				if((micros1 - lastPrint) >= 1000000) {
					fprintf(stderr, "\033[44;37mFRAMERATE: %d fps; RENDERDELAY: %d us\033[0m\n",
					PRNT(0, "\033[44;37mFRAMERATE: %d fps; RENDERDELAY: %d us\033[0m\n",
						int(frames-lastFrames), int(renderDelay));
					lastPrint = micros1;
					lastFrames = frames;
				nextIndex++;
			}
			fprintf(stderr, "%d unique shader keys\n", (int)shaderIDs2.size());
			fprintf(stderr, "%d shader programs\n", nextIndex);
			PRNT(0, "%d unique shader keys\n", (int)shaderIDs2.size());
			PRNT(0, "%d shader programs\n", nextIndex);
		}
		int getShaderProgramIndex(const VideoSegment& seg) {
			assert(shaderIDs2.find(shaderKey(seg)) != shaderIDs2.end());
@@ -137,10 +137,10 @@ namespace ytpmv {
			if(!evt.off) { // note on
				notesActive[evt.segmentIndex] = curTimeFrames;
				const VideoSegment& s = segments.at(evt.segmentIndex);
				fprintf(stderr, "videoclip on: %5d:  dur %3.2fs\n", evt.segmentIndex, s.durationSeconds());
				PRNT(0, "videoclip on: %5d:  dur %3.2fs\n", evt.segmentIndex, s.durationSeconds());
			} else {
				notesActive.erase(evt.segmentIndex);
				fprintf(stderr, "videoclip off:%5d\n", evt.segmentIndex);
				PRNT(0, "videoclip off:%5d\n", evt.segmentIndex);
			}

			if(curTimeFrames >= nextTimeFrames) continue;
@@ -298,7 +298,7 @@ namespace ytpmv {
			if(frame <= curFrame) return true;

			bool encounteredEvent = false;
			//fprintf(stderr, "%d events\n", (int)events.size());
			//PRNT(0, "%d events\n", (int)events.size());
			// go through events until one beyond the requested frame is encountered
			while(lastEventIndex < (int)events.size()) {
				NoteEventV& evt = events[lastEventIndex];
@@ -307,14 +307,14 @@ namespace ytpmv {

				// if the event's start time is after curFrame then we haven't processed it yet
				if(evt.t > curFrame) {
					fprintf(stderr, "event %d: ", lastEventIndex);
					PRNT(1, "event %d: ", lastEventIndex);
					if(!evt.off) { // note on
						notesActive[evt.segmentIndex] = evt.t;
						const VideoSegment& s = segments.at(evt.segmentIndex);
						fprintf(stderr, "videoclip on: %5d:  dur %3.2fs\n", evt.segmentIndex, s.durationSeconds());
						PRNT(1, "videoclip on: %5d:  dur %3.2fs\n", evt.segmentIndex, s.durationSeconds());
					} else {
						notesActive.erase(evt.segmentIndex);
						fprintf(stderr, "videoclip off:%5d\n", evt.segmentIndex);
						PRNT(1, "videoclip off:%5d\n", evt.segmentIndex);
					}
					encounteredEvent = true;
				}
        
      
