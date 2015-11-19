#include "LegoMan.h"
// better to include the *.h in the *.cpp file than *.h file ,otherwise will cause LNK 1169 problem
#define STB_IMAGE_IMPLEMENTATION
#include "stb_image.hpp"

void getLegoManTexture(GLuint Tid[]) {
	int imageWidth;
	int imageHeight;
	int pix;
	glGenTextures(30, Tid);
	for (size_t x = 0; x < LegoMan::materials.size(); x++) {
		if (LegoMan::materials[x].diffuse_texname.empty()) {
			Tid[x] = INT_MAX;
		}
		else {
			std::string _base = BASE;
			std::string Jname = _base + LegoMan::materials[x].diffuse_texname; // filename
			unsigned char* data = stbi_load(Jname.c_str(), &imageWidth, &imageHeight, &pix, 3);
			glBindTexture(GL_TEXTURE_2D, Tid[x]);
			glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
			glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
			glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT);
			glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT);
			glTexEnvf(GL_TEXTURE_ENV, GL_TEXTURE_ENV_MODE, GL_REPLACE);
			glTexImage2D(GL_TEXTURE_2D, 0, 3, imageWidth, imageHeight, 0, GL_RGB, GL_UNSIGNED_BYTE, data);
		}
	}
}

bool objLoader(vector<tinyobj::shape_t> &shapes, vector<tinyobj::material_t> &materials) {
	string _lego_man = LEGO_MAN;
	string _base = BASE;
	string err = tinyobj::LoadObj(shapes, materials,_lego_man.c_str(),_base.c_str());
	if (!err.empty()) {
		cerr << err << endl;
		return false;
	}
	return true;
}


void LegoMan::drawLegoMan(){
	vec3_flag temp = { 0,0,0,0 };
	vec3 move = { 0,0,0 };
	int rotate = 0;
	glEnable(GL_TEXTURE_2D);
	glEnable(GL_LIGHTING);
	glEnable(GL_LIGHT0);
	glDisable(GL_BLEND);
	for (size_t i = 0; i < LegoMan::shapes.size(); i++) { // get shapes/
		vector<int> m_id = LegoMan::shapes[i].mesh.material_ids;
		vector<unsigned int> indices = LegoMan::shapes[i].mesh.indices;
		vector<float> positions = LegoMan::shapes[i].mesh.positions;
		vector<float> normals = LegoMan::shapes[i].mesh.normals;
		vector<float> texture = LegoMan::shapes[i].mesh.texcoords;
		if (LegoMan::shapes[i].name != cha[character]) continue;
		for(size_t f = 0; f <indices.size()/3; f++){
			int mID = m_id[f];
			if(LegoMan::Tid[mID] != INT_MAX){ // HAS TEXTURE
				glBindTexture(GL_TEXTURE_2D,LegoMan::Tid[mID]);		
			}else{ // bind material
				glMaterialfv(GL_FRONT_AND_BACK,GL_AMBIENT,LegoMan::materials[mID].ambient);
				glMaterialfv(GL_FRONT_AND_BACK,GL_DIFFUSE,LegoMan::materials[mID].diffuse);
				glMaterialfv(GL_FRONT_AND_BACK,GL_EMISSION,LegoMan::materials[mID].emission);
				glMaterialfv(GL_FRONT_AND_BACK,GL_SPECULAR,LegoMan::materials[mID].specular);
				glMaterialf(GL_FRONT_AND_BACK,GL_SHININESS,LegoMan::materials[mID].shininess);
			}
			glBegin(GL_TRIANGLES);
			for (size_t z = 0; z<3;z++){ // build a trangle
				int index = indices[3*f+z]*3; //get the current Index of the vertex
				int Tindex = indices[3*f+z]*2;
				if(LegoMan::Tid[mID] != INT_MAX){
					glTexCoord2f(texture[Tindex],1-texture[Tindex+1]);
				}else{
					//printf("ffff\n");
				}
				glNormal3f(normals[index],normals[index+1],normals[index+2]);
				glVertex3f(positions[index],positions[index+1],positions[index+2]);
				
			}
			glEnd();
		}
		glBindTexture(GL_TEXTURE_2D,0);			
	}
	glDisable(GL_TEXTURE_2D);
	glDisable(GL_LIGHT0);
	glDisable(GL_LIGHTING);
	glEnable(GL_BLEND);
}

LegoMan::LegoMan(LEGOCHARACTER c){
		// specfic the model;
		character = c;
}

LegoMan* LegoMan::move(vec3 v){
	vec3_flag temp = { 0,0,0,0 };
	temp.vector = v;
	temp.flag = 0;
	history.push(temp);
	return this;
}
LegoMan* LegoMan::rotate(int v){
	vec3_flag temp = { 0,0,0,0 };
	temp.flag = v;
	history.push(temp);
	return this;
}

LegoMan* LegoMan::reflash(){
	vec3_flag temp = {0,0,0,0};
	vec3 move = { 0,0,0 };
	int rotate = 0;

	while (history.isempty() == false) {
		history.pop(temp);
		switch (temp.flag)
		{
		case 0:
			move.x += temp.vector.x;
			move.y += temp.vector.y;
			move.z += temp.vector.z;
			break;
		case 1:
			rotate += temp.flag;
			break;
		case 2:
			rotate += temp.flag;
			break;
		case 3:
			rotate += temp.flag;
			break;
		default:
			break;
		}
	}
	position.x += move.x;
	position.y += move.y;
	position.z += move.z;
	rotate_flag = (rotate_flag + rotate) % 4;

	glPushMatrix();
	glTranslatef(position.x, position.y, position.z);
	switch (character)
	{
	case LEGO1:
		glRotatef(rotate_flag * 90, 0.0, 1.0, 0.0);
		glTranslatef(0, 0, -4.0);
		break;
	case LEGO2:
		break;
	case LEGO3:
		break;
	case LEGO4:
		break;
	default:
		break;
	}
	
	drawLegoMan();
	glPopMatrix();
	return this;
}
LegoMan* LegoMan::reset(){
	return this;
}	

LegoMan::~LegoMan(){

}
void LegoMan::Init() {
	objLoader(LegoMan::shapes,LegoMan::materials);
	getLegoManTexture(LegoMan::Tid);
}

