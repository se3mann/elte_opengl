#include "MyApp.h"
#include "GLUtils.hpp"

#include <math.h>



CMyApp::CMyApp()
{
}

CMyApp::~CMyApp()
{
}

void CMyApp::InitCube()
{
	//struct Vertex{ glm::vec3 position; glm::vec3 color };
	std::vector<Vertex>vertices;

	
	//front									 
	vertices.push_back({ glm::vec3(-1, -1, +1), glm::vec3(0, 0, 0) });
	vertices.push_back({ glm::vec3(+1, -1, +1), glm::vec3(1, 0, 0) });
	vertices.push_back({ glm::vec3(-1, +1, +1), glm::vec3(0, 1, 0) });
	vertices.push_back({ glm::vec3(+1, +1, +1), glm::vec3(1, 1, 0) });
	//back												   
	vertices.push_back({ glm::vec3(+1, -1, -1), glm::vec3(0, 0, 0) });
	vertices.push_back({ glm::vec3(-1, -1, -1), glm::vec3(1, 0, 0) });
	vertices.push_back({ glm::vec3(+1, +1, -1), glm::vec3(0, 1, 0) });
	vertices.push_back({ glm::vec3(-1, +1, -1), glm::vec3(1, 1, 0) });
	//right									 			   			
	vertices.push_back({ glm::vec3(+1, -1, +1), glm::vec3(0, 0, 0) });
	vertices.push_back({ glm::vec3(+1, -1, -1), glm::vec3(1, 0, 0) });
	vertices.push_back({ glm::vec3(+1, +1, +1), glm::vec3(0, 1, 0) });
	vertices.push_back({ glm::vec3(+1, +1, -1), glm::vec3(1, 1, 0) });
	//left									 			   			
	vertices.push_back({ glm::vec3(-1, -1, -1), glm::vec3(0, 0, 0) });
	vertices.push_back({ glm::vec3(-1, -1, +1), glm::vec3(1, 0, 0) });
	vertices.push_back({ glm::vec3(-1, +1, -1), glm::vec3(0, 1, 0) });
	vertices.push_back({ glm::vec3(-1, +1, +1), glm::vec3(1, 1, 0) });
	//top									 			   			
	vertices.push_back({ glm::vec3(-1, +1, +1), glm::vec3(0, 0, 0) });
	vertices.push_back({ glm::vec3(+1, +1, +1), glm::vec3(1, 0, 0) });
	vertices.push_back({ glm::vec3(-1, +1, -1), glm::vec3(0, 1, 0) });
	vertices.push_back({ glm::vec3(+1, +1, -1), glm::vec3(1, 1, 0) });
	//bottom								 			   			
	vertices.push_back({ glm::vec3(-1, -1, -1), glm::vec3(0, 0, 0) });
	vertices.push_back({ glm::vec3(+1, -1, -1), glm::vec3(1, 0, 0) });
	vertices.push_back({ glm::vec3(-1, -1, +1), glm::vec3(0, 1, 0) });
	vertices.push_back({ glm::vec3(+1, -1, +1), glm::vec3(1, 1, 0) });
	
	
	/*
	//random numbers for color
	for (int i = 0; i < 24; i++) {
		//float rectangle_color = (float)rand() / RAND_MAX;
		vertices[i].c = glm::vec3((float)rand() / RAND_MAX, (float)rand() / RAND_MAX, (float)rand() / RAND_MAX);
		//vertices[i].c = glm::vec3(rectangle_color,rectangle_color,rectangle_color);
	}
	*/
	
	//normalized vectors for color
	for (int i = 0; i < 24; i++) {
		vertices[i].c = glm::normalize(vertices[i].p);
	}
	

	/*
	//random color at the 8 vertex
	std::vector<glm::vec3>random_color;

	for (int i = 0; i < 8; i++) {
		glm::vec3 color = glm::vec3((float)rand()/(float)RAND_MAX, (float)rand() / (float)RAND_MAX, (float)rand() / (float)RAND_MAX);
		random_color.push_back(color);
	}
	//front									 
	vertices.push_back({ glm::vec3(-1, -1, +1), random_color[0] });
	vertices.push_back({ glm::vec3(+1, -1, +1), random_color[1] });
	vertices.push_back({ glm::vec3(-1, +1, +1), random_color[3] });
	vertices.push_back({ glm::vec3(+1, +1, +1), random_color[4] });
	//back												   
	vertices.push_back({ glm::vec3(+1, -1, -1), random_color[5] });
	vertices.push_back({ glm::vec3(-1, -1, -1), random_color[6] });
	vertices.push_back({ glm::vec3(+1, +1, -1), random_color[7] });
	vertices.push_back({ glm::vec3(-1, +1, -1), random_color[2] });
	//right									 			   			
	vertices.push_back({ glm::vec3(+1, -1, +1), random_color[1] });
	vertices.push_back({ glm::vec3(+1, -1, -1), random_color[5] });
	vertices.push_back({ glm::vec3(+1, +1, +1), random_color[4] });
	vertices.push_back({ glm::vec3(+1, +1, -1), random_color[7] });
	//left									 			   			
	vertices.push_back({ glm::vec3(-1, -1, -1), random_color[6] });
	vertices.push_back({ glm::vec3(-1, -1, +1), random_color[0] });
	vertices.push_back({ glm::vec3(-1, +1, -1), random_color[2] });
	vertices.push_back({ glm::vec3(-1, +1, +1), random_color[3] });
	//top									 			   			
	vertices.push_back({ glm::vec3(-1, +1, +1), random_color[3] });
	vertices.push_back({ glm::vec3(+1, +1, +1), random_color[4] });
	vertices.push_back({ glm::vec3(-1, +1, -1), random_color[2] });
	vertices.push_back({ glm::vec3(+1, +1, -1), random_color[7] });
	//bottom								 			   			
	vertices.push_back({ glm::vec3(-1, -1, -1), random_color[6] });
	vertices.push_back({ glm::vec3(+1, -1, -1), random_color[5] });
	vertices.push_back({ glm::vec3(-1, -1, +1), random_color[0] });
	vertices.push_back({ glm::vec3(+1, -1, +1), random_color[1] });
	*/

	GLushort indices[36];
	int index = 0;
	//4 cs??cspontonk??nt 6 index elt??rol??sa
	for (int i = 0; i < 6 * 4; i += 4)
	{
		indices[index + 0] = i + 0;
		indices[index + 1] = i + 1;
		indices[index + 2] = i + 2;
		indices[index + 3] = i + 1;
		indices[index + 4] = i + 3;
		indices[index + 5] = i + 2;
		index += 6;
	}

	glGenVertexArrays(1, &m_cube_vaoID);
	glBindVertexArray(m_cube_vaoID);

	glGenBuffers(1, &m_cube_vboID);
	glBindBuffer(GL_ARRAY_BUFFER, m_cube_vboID);
	glBufferData(GL_ARRAY_BUFFER, vertices.size() * sizeof(Vertex), &vertices[0], GL_STATIC_DRAW);

	glEnableVertexAttribArray(0);
	glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, sizeof(Vertex), 0);

	glEnableVertexAttribArray(1);
	glVertexAttribPointer(1, 2, GL_FLOAT, GL_FALSE, sizeof(Vertex), (void*)(sizeof(glm::vec3)));

	glGenBuffers(1, &m_cube_ibID);
	glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, m_cube_ibID);
	glBufferData(GL_ELEMENT_ARRAY_BUFFER, sizeof(indices), indices, GL_STATIC_DRAW);

	glBindVertexArray(0);
	glBindBuffer(GL_ARRAY_BUFFER, 0);
	glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, 0);

}

void CMyApp::InitShaders()
{
	//
	// shaderek bet??lt??se
	//
	GLuint vs_ID = loadShader(GL_VERTEX_SHADER, "myVert.vert");
	GLuint fs_ID = loadShader(GL_FRAGMENT_SHADER, "myFrag.frag");

	// a shadereket t??rol?? program l??trehoz??sa
	m_programID = glCreateProgram();

	// adjuk hozz?? a programhoz a shadereket
	glAttachShader(m_programID, vs_ID);
	glAttachShader(m_programID, fs_ID);

	// VAO-beli attrib??tumok hozz??rendel??se a shader v??ltoz??khoz
	// FONTOS: linkel??s el??tt kell ezt megtenni!
	glBindAttribLocation(m_programID,	// shaderprogram azonos??t??ja, amib??l egy v??ltoz??hoz szeretn??nk hozz??rendel??st csin??lni
		0,				// a VAO-beli azonos??t?? index
		"vs_in_pos");	// a shader-beli v??ltoz??n??v
	glBindAttribLocation(m_programID, 1, "vs_in_tex0");

	// illessz??k ??ssze a shadereket (kimen??-bemen?? v??ltoz??k ??sszerendel??se stb.)
	glLinkProgram(m_programID);

	// linkeles ellenorzese
	GLint infoLogLength = 0, result = 0;

	glGetProgramiv(m_programID, GL_LINK_STATUS, &result);
	glGetProgramiv(m_programID, GL_INFO_LOG_LENGTH, &infoLogLength);
	if (GL_FALSE == result || infoLogLength != 0)
	{
		std::vector<char> VertexShaderErrorMessage(infoLogLength);
		glGetProgramInfoLog(m_programID, infoLogLength, nullptr, VertexShaderErrorMessage.data());
		std::cerr << "[glLinkProgram] Shader linking error:\n" << &VertexShaderErrorMessage[0] << std::endl;
	}

	// mar nincs ezekre szukseg
	glDeleteShader(vs_ID);
	glDeleteShader(fs_ID);
}

bool CMyApp::Init()
{
	// t??rl??si sz??n legyen k??kes
	glClearColor(0.125f, 0.25f, 0.5f, 1.0f);

	glEnable(GL_CULL_FACE); // kapcsoljuk be a hatrafele nezo lapok eldobasat
	glEnable(GL_DEPTH_TEST); // m??lys??gi teszt bekapcsol??sa (takar??s)
	glCullFace(GL_BACK); // GL_BACK: a kamer??t??l "elfel??" n??z?? lapok, GL_FRONT: a kamera fel?? n??z?? lapok

	InitCube();
	InitShaders();

	// vet??t??si m??trix l??trehoz??sa
	m_matProj = glm::perspective(45.0f, 640 / 480.0f, 1.0f, 1000.0f);

	// shader-beli transzform??ci??s m??trixok c??m??nek lek??rdez??se
	m_loc_mvp = glGetUniformLocation( m_programID, "MVP");

	return true;
}

void CMyApp::Clean()
{
	glDeleteBuffers(1, &m_cube_vboID);
	glDeleteBuffers(1, &m_cube_ibID);

	glDeleteVertexArrays(1, &m_cube_vaoID);

	glDeleteProgram( m_programID );
}

void CMyApp::Update()
{
	// n??zeti transzform??ci?? be??ll??t??sa
	float t = SDL_GetTicks() / 1000.0f;
	m_matView = glm::lookAt(glm::vec3( 20,  20,  20),		// honnan n??zz??k a sz??nteret
							//glm::vec3(5 * cos(t), 5, 5 * sin(t)),
							glm::vec3( 0,  0,  0),		// a sz??nt??r melyik pontj??t n??zz??k
							glm::vec3( 0,  1,  0));		// felfel?? mutat?? ir??ny a vil??gban
}


void CMyApp::Render()
{
	// t??r??lj??k a frampuffert (GL_COLOR_BUFFER_BIT) ??s a m??lys??gi Z puffert (GL_DEPTH_BUFFER_BIT)
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

	// shader bekapcsolasa, ebben a projektben a teljes programot jel??li, hisz nem v??ltunk a shaderek k??z??tt
	glUseProgram( m_programID );

	/*

	GLM transzform??ci??s m??trixokra p??ld??k:
		glm::rotate<float>( sz??g, glm::vec3(tengely_x, tengely_y, tengely_z) ) <- tengely_{xyz} k??r??li elforgat??s
		glm::translate<float>( glm::vec3(eltol_x, eltol_y, eltol_z) ) <- eltol??s
		glm::scale<float>( glm::vec3(s_x, s_y, s_z) ) <- l??pt??kez??s

	*/

	
	//A kocka kirajzol??sa
	
	// V??ltsunk ??t a kocka VAO-j??ra
	glBindVertexArray(m_cube_vaoID);

	
	if (is_spinning) {
		//mozg??s g??rb??n
		float t = SDL_GetTicks() / (1000.0f * 6.0f);
		float x = sin(2 * M_PI * t) * 10;
		//id?? a forg??sra a saj??t tenger k??r??l
		float time = SDL_GetTicks() / 1000.0f * 6.28f;

		m_matWorld = glm::translate<float>(glm::vec3(x, 0, 0.01f * (x * x * x) + 0.05f * (x * x))) *glm::rotate(time,glm::vec3(0,1,0));
		glm::mat4 mvp = m_matProj * m_matView * m_matWorld;
		// a k??z??ps?? kocka kirajzol??sa

		//mvp = m_matProj * m_matView * m_matWorld;
		glUniformMatrix4fv(m_loc_mvp, 1, GL_FALSE, &(mvp[0][0]));
		//glUniformMatrix4fv(m_loc_w, 1, GL_FALSE, &(m_matWorld[0][0]));
		glDrawElements(GL_TRIANGLES, 36, GL_UNSIGNED_SHORT, 0);


		//T alak
		float a = 2.0f; //kocka ??l??nek hossza
		{
			m_matWorld = glm::translate<float>(glm::vec3(x, 0, 0.01f * (x * x * x) + 0.05f * (x * x))) *glm::translate(glm::vec3(a, 0, 0)) * glm::rotate(time, glm::vec3(0, 1, 0));
			mvp = m_matProj * m_matView * m_matWorld;
			glUniformMatrix4fv(m_loc_mvp, 1, GL_FALSE, &(mvp[0][0]));
			glDrawElements(GL_TRIANGLES, 36, GL_UNSIGNED_SHORT, 0);
		}
		{
			m_matWorld = glm::translate<float>(glm::vec3(x, 0, 0.01f * (x * x * x) + 0.05f * (x * x))) *glm::translate(glm::vec3(-a, 0, 0)) * glm::rotate(time, glm::vec3(0, 1, 0));
			mvp = m_matProj * m_matView * m_matWorld;
			glUniformMatrix4fv(m_loc_mvp, 1, GL_FALSE, &(mvp[0][0]));
			glDrawElements(GL_TRIANGLES, 36, GL_UNSIGNED_SHORT, 0);
		}
		for (int i = 1; i <= 2; i++) {
			{
				m_matWorld = glm::translate<float>(glm::vec3(x, 0, 0.01f * (x * x * x) + 0.05f * (x * x))) *glm::translate(glm::vec3(0, -1 * a * i, 0)) * glm::rotate(time, glm::vec3(0, 1, 0));
				mvp = m_matProj * m_matView * m_matWorld;
				glUniformMatrix4fv(m_loc_mvp, 1, GL_FALSE, &(mvp[0][0]));
				glDrawElements(GL_TRIANGLES, 36, GL_UNSIGNED_SHORT, 0);
			}
		}
	}
	else {
		//mozg??s g??rb??n
		float t = SDL_GetTicks() / (1000.0f * 6.0f);
		float x = sin(2 * M_PI * t) * 10;
		
		
		m_matWorld = glm::translate<float>(glm::vec3(x, 0, 0.01f * (x * x * x) + 0.05f * (x * x)));
		// glm::translate(glm::vec3(0, 0, 0));
		glm::mat4 mvp = m_matProj * m_matView * m_matWorld;
		// a k??z??ps?? kocka kirajzol??sa

		//mvp = m_matProj * m_matView * m_matWorld;
		glUniformMatrix4fv(m_loc_mvp, 1, GL_FALSE, &(mvp[0][0]));
		//glUniformMatrix4fv(m_loc_w, 1, GL_FALSE, &(m_matWorld[0][0]));
		glDrawElements(GL_TRIANGLES, 36, GL_UNSIGNED_SHORT, 0);


		//T alak
		float a = 2.0f; //kocka ??l??nek hossza
		{
			m_matWorld = glm::translate<float>(glm::vec3(x, 0, 0.01f * (x * x * x) + 0.05f * (x * x))) *glm::translate(glm::vec3(a, 0, 0));
			mvp = m_matProj * m_matView * m_matWorld;
			glUniformMatrix4fv(m_loc_mvp, 1, GL_FALSE, &(mvp[0][0]));
			glDrawElements(GL_TRIANGLES, 36, GL_UNSIGNED_SHORT, 0);
		}
		{
			m_matWorld = glm::translate<float>(glm::vec3(x, 0, 0.01f * (x * x * x) + 0.05f * (x * x))) * glm::translate(glm::vec3(-a, 0, 0));
			mvp = m_matProj * m_matView * m_matWorld;
			glUniformMatrix4fv(m_loc_mvp, 1, GL_FALSE, &(mvp[0][0]));
			glDrawElements(GL_TRIANGLES, 36, GL_UNSIGNED_SHORT, 0);
		}
		for (int i = 1; i <= 2; i++) {
			{
				m_matWorld = glm::translate<float>(glm::vec3(x, 0, 0.01f * (x * x * x) + 0.05f * (x * x))) * glm::translate(glm::vec3(0, -1 * a * i, 0));
				mvp = m_matProj * m_matView * m_matWorld;
				glUniformMatrix4fv(m_loc_mvp, 1, GL_FALSE, &(mvp[0][0]));
				glDrawElements(GL_TRIANGLES, 36, GL_UNSIGNED_SHORT, 0);
			}
		}
	}
	
	
	// VAO kikapcsolasa
	glBindVertexArray(0);

	// shader kikapcsolasa
	glUseProgram( 0 );
}

void CMyApp::KeyboardDown(SDL_KeyboardEvent& key)
{
	if (key.keysym.sym == SDLK_SPACE)
	{
		if (is_spinning) {
			is_spinning = false;
		}
		else {
			is_spinning = true;
		}
	}
}

void CMyApp::KeyboardUp(SDL_KeyboardEvent& key)
{
}

void CMyApp::MouseMove(SDL_MouseMotionEvent& mouse)
{

}

void CMyApp::MouseDown(SDL_MouseButtonEvent& mouse)
{
}

void CMyApp::MouseUp(SDL_MouseButtonEvent& mouse)
{
}

void CMyApp::MouseWheel(SDL_MouseWheelEvent& wheel)
{
}

// a k??t param??terbe az ??j ablakm??ret sz??less??ge (_w) ??s magass??ga (_h) tal??lhat??
void CMyApp::Resize(int _w, int _h)
{
	glViewport(0, 0, _w, _h);
	
	// vet??t??si m??trix be??ll??t??sa
	m_matProj = glm::perspective(glm::radians(60.0f),	// 60 fokos nyil??sszog radi??nban
		_w / (float)_h,			// ablakm??reteknek megfelel?? n??zeti ar??ny
		0.01f,					// k??zeli v??g??s??k
		1000.0f);				// t??voli v??g??s??k
}




