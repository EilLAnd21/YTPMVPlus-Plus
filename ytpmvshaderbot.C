namespace ytpmv {
	string defaultVertexShader = "#version 330 core\n\
	layout(location = 0) in vec3 myPos;\
	layout(location = 1) in vec2 texPos;\
	uniform vec2 coordBase;\n\
	uniform mat2 coordTransform;\n\
	smooth out vec2 uv;\n\
	void main(){\
		gl_Position.xy = coordBase + myPos.xy * coordTransform;\
		gl_Position.z = myPos.z;\n\
		gl_Position.w = 1.0;\
		uv = texPos;\n\
	}\
	";
	string defaultVertexShader = R"aaaaa(
		#version 330 core
		layout(location = 0) in vec3 myPos;
		layout(location = 1) in vec2 texPos;
		uniform vec2 coordBase;
		uniform mat2 coordTransform;
		smooth out vec2 uv;
		void main(){
			gl_Position.xy = coordBase + myPos.xy * coordTransform;
			gl_Position.z = myPos.z;
			gl_Position.w = 1.0;
			uv = texPos;
		}
		)aaaaa";
	string defaultFragmentShader = R"aaaaa(
		#version 330 core
		smooth in vec2 uv;
		out vec4 color; 
		uniform sampler2D image;
		void main() {
			color = vec4(texture2D(image, uv).rgb, 1.0);
		}
		)aaaaa";

	GLuint loadShader2(string VertexShaderCode, string FragmentShaderCode) {
		// Create the shaders
    
    	extern string defaultVertexShader;
	extern string defaultFragmentShader;

	// given only fragment shader body, generate the full shader code
	string FrameRenderer2_generateCode(string code, int maxParams);

					shaderIDs2[key] = shaderIDs[hashKey];
					continue;
				}
				if(seg.shader == nullptr && seg.fragmentShader == nullptr) {
					throw logic_error("segment " + to_string(i) + " does not have shader code");
				}
				shaderIDs[hashKey] = nextIndex;
				shaderIDs2[key] = nextIndex;

				if(seg.vertexShader == nullptr)
					shaders.push_back(defaultVertexShader);
				else shaders.push_back(*seg.vertexShader);

				if(seg.fragmentShader == nullptr)
				if(seg.fragmentShader != nullptr)
					shaders.push_back(*seg.fragmentShader);
				else if(seg.shader != nullptr)
					shaders.push_back(FrameRenderer2_generateCode(*seg.shader, MAXUSERPARAMS));
				else shaders.push_back(*seg.fragmentShader);
				else shaders.push_back(defaultFragmentShader);

				nextIndex++;
			}
