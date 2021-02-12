		// convert note list into note event list
		vector<NoteEvent> events;
		for(int i=0;i<(int)segments.size();i++) {
			if(segments[i].startSeconds >= segments[i].endSeconds) continue;
			NoteEvent evt;
			evt.t = segments[i].startSeconds;
			evt.off = false;
      
		// convert note list into note event list
		vector<NoteEventV> events;
		for(int i=0;i<(int)segments.size();i++) {
			if(segments[i].startSeconds >= segments[i].endSeconds) continue;
			NoteEventV evt;
			evt.t = (int)round(segments[i].startSeconds*fps);
			evt.off = false;
      
      			// convert note list into note event list
			for(int i=0;i<(int)segments.size();i++) {
				if(segments[i].startSeconds >= segments[i].endSeconds) continue;
				NoteEventV evt;
				evt.t = (int)round(segments[i].startSeconds*fps);
				evt.off = false;
