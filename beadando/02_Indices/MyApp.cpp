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
	//4 csúcspontonként 6 index eltárolása
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
	// shaderek betöltése
	//
	GLuint vs_ID = loadShader(GL_VERTEX_SHADER, "myVert.vert");
	GLuint fs_ID = loadShader(GL_FRAGMENT_SHADER, "myFrag.frag");

	// a shadereket tároló program létrehozása
	m_programID = glCreateProgram();

	// adjuk hozzá a programhoz a shadereket
	glAttachShader(m_programID, vs_ID);
	glAttachShader(m_programID, fs_ID);

	// VAO-beli attribútumok hozzárendelése a shader változókhoz
	// FONTOS: linkelés előtt kell ezt megtenni!
	glBindAttribLocation(m_programID,	// shaderprogram azonosítója, amiből egy változóhoz szeretnénk hozzárendelést csinálni
		0,				// a VAO-beli azonosító index
		"vs_in_pos");	// a shader-beli változónév
	glBindAttribLocation(m_programID, 1, "vs_in_tex0");

	// illesszük össze a shadereket (kimenő-bemenő változók összerendelése stb.)
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
	// törlési szín legyen kékes
	glClearColor(0.125f, 0.25f, 0.5f, 1.0f);

	glEnable(GL_CULL_FACE); // kapcsoljuk be a hatrafele nezo lapok eldobasat
	glEnable(GL_DEPTH_TEST); // mélységi teszt bekapcsolása (takarás)
	glCullFace(GL_BACK); // GL_BACK: a kamerától "elfelé" néző lapok, GL_FRONT: a kamera felé néző lapok

	InitCube();
	InitShaders();

	// vetítési mátrix létrehozása
	m_matProj = glm::perspective(45.0f, 640 / 480.0f, 1.0f, 1000.0f);

	// shader-beli transzformációs mátrixok címének lekérdezése
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
	// nézeti transzformáció beállítása
	float t = SDL_GetTicks() / 1000.0f;
	m_matView = glm::lookAt(glm::vec3( 20,  20,  20),		// honnan nézzük a színteret
							//glm::vec3(5 * cos(t), 5, 5 * sin(t)),
							glm::vec3( 0,  0,  0),		// a színtér melyik pontját nézzük
							glm::vec3( 0,  1,  0));		// felfelé mutató irány a világban
}


void CMyApp::Render()
{
	// töröljük a frampuffert (GL_COLOR_BUFFER_BIT) és a mélységi Z puffert (GL_DEPTH_BUFFER_BIT)
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

	// shader bekapcsolasa, ebben a projektben a teljes programot jelöli, hisz nem váltunk a shaderek között
	glUseProgram( m_programID );

	/*

	GLM transzformációs mátrixokra példák:
		glm::rotate<float>( szög, glm::vec3(tengely_x, tengely_y, tengely_z) ) <- tengely_{xyz} körüli elforgatás
		glm::translate<float>( glm::vec3(eltol_x, eltol_y, eltol_z) ) <- eltolás
		glm::scale<float>( glm::vec3(s_x, s_y, s_z) ) <- léptékezés

	*/

	
	//A kocka kirajzolása
	
	// Váltsunk át a kocka VAO-jára
	glBindVertexArray(m_cube_vaoID);

	
	if (is_spinning) {
		//mozgás görbén
		float t = SDL_GetTicks() / (1000.0f * 6.0f);
		float x = sin(2 * M_PI * t) * 10;
		//idő a forgásra a saját tenger körül
		float time = SDL_GetTicks() / 1000.0f * 6.28f;

		m_matWorld = glm::translate<float>(glm::vec3(x, 0, 0.01f * (x * x * x) + 0.05f * (x * x))) *glm::rotate(time,glm::vec3(0,1,0));
		glm::mat4 mvp = m_matProj * m_matView * m_matWorld;
		// a középső kocka kirajzolása

		//mvp = m_matProj * m_matView * m_matWorld;
		glUniformMatrix4fv(m_loc_mvp, 1, GL_FALSE, &(mvp[0][0]));
		//glUniformMatrix4fv(m_loc_w, 1, GL_FALSE, &(m_matWorld[0][0]));
		glDrawElements(GL_TRIANGLES, 36, GL_UNSIGNED_SHORT, 0);


		//T alak
		float a = 2.0f; //kocka élének hossza
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
		//mozgás görbén
		float t = SDL_GetTicks() / (1000.0f * 6.0f);
		float x = sin(2 * M_PI * t) * 10;
		
		
		m_matWorld = glm::translate<float>(glm::vec3(x, 0, 0.01f * (x * x * x) + 0.05f * (x * x)));
		// glm::translate(glm::vec3(0, 0, 0));
		glm::mat4 mvp = m_matProj * m_matView * m_matWorld;
		// a középső kocka kirajzolása

		//mvp = m_matProj * m_matView * m_matWorld;
		glUniformMatrix4fv(m_loc_mvp, 1, GL_FALSE, &(mvp[0][0]));
		//glUniformMatrix4fv(m_loc_w, 1, GL_FALSE, &(m_matWorld[0][0]));
		glDrawElements(GL_TRIANGLES, 36, GL_UNSIGNED_SHORT, 0);


		//T alak
		float a = 2.0f; //kocka élének hossza
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

// a két paraméterbe az új ablakméret szélessége (_w) és magassága (_h) található
void CMyApp::Resize(int _w, int _h)
{
	glViewport(0, 0, _w, _h);
	
	// vetítési mátrix beállítása
	m_matProj = glm::perspective(glm::radians(60.0f),	// 60 fokos nyilásszog radiánban
		_w / (float)_h,			// ablakméreteknek megfelelő nézeti arány
		0.01f,					// közeli vágósík
		1000.0f);				// távoli vágósík
}




