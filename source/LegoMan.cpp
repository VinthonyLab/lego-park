#include "LegoMan.h"


void LegoMan::drawLegoMan(){
	GLfloat lightpos[] = {10.0, 20.0, 10.0, 0.0};
	GLfloat light_KA[] = {1.0,1.0,1.0,1.0};
	GLfloat light_KD[] = {1.0,1.0,1.0,1.0};
	GLfloat light_KS[] = {1.0,1.0,1.0,1.0};
	glLightfv(GL_LIGHT0, GL_POSITION, lightpos);
	glLightfv(GL_LIGHT0, GL_AMBIENT, light_KA);
	glLightfv(GL_LIGHT0, GL_DIFFUSE, light_KD);
	glLightfv(GL_LIGHT0, GL_SPECULAR, light_KS);
	for (size_t i = 0; i < LegoMan::shapes.size(); i++) { // get shapes/
		vector<int> m_id = LegoMan::shapes[i].mesh.material_ids;
		vector<char32_t> indices = LegoMan::shapes[i].mesh.indices;
		vector<float> positions = LegoMan::shapes[i].mesh.positions;
		vector<float> normals = LegoMan::shapes[i].mesh.normals;
		vector<float> texture = LegoMan::shapes[i].mesh.texcoords;
		glEnable(GL_TEXTURE_2D);
		glPushMatrix();
		for(size_t f = 0; f <indices.size()/3; f++){
			int mID = m_id[f];
			if(LegoMan::Tid[mID] != INT_MAX){ // HAS TEXTUE
				glBindTexture(GL_TEXTURE_2D,LegoMan::Tid[mID]);		
			}
			glBegin(GL_TRIANGLES);
			for (size_t z = 0; z<3;z++){ // build a trangle
				int index = indices[3*f+z]*3; //get the current Index of the vertex
				int Tindex = indices[3*f+z]*2;
				
				glMaterialfv(GL_FRONT_AND_BACK,GL_AMBIENT,LegoMan::materials[mID].ambient);
				glMaterialfv(GL_FRONT_AND_BACK,GL_DIFFUSE,LegoMan::materials[mID].diffuse);
				glMaterialfv(GL_FRONT_AND_BACK,GL_EMISSION,LegoMan::materials[mID].emission);
				glMaterialfv(GL_FRONT_AND_BACK,GL_SPECULAR,LegoMan::materials[mID].specular);
				glMaterialf(GL_FRONT_AND_BACK,GL_SHININESS,LegoMan::materials[mID].shininess);
				
				if(LegoMan::Tid[mID] != INT_MAX){
					glTexCoord2f(texture[Tindex],1-texture[Tindex+1]);
				}else{
					//printf("ffff\n");
				}
				glNormal3f(normals[index],normals[index+1],normals[index+2]);
				glVertex3f(positions[index],positions[index+1],positions[index+2]);
			}
		}
		glEnd();
		glBindTexture(GL_TEXTURE_2D,0);	
		glPopMatrix();
	}
}

LegoMan::LegoMan(int c){
		// specfic the model;
		character = c;
}

LegoMan* LegoMan::move(vec3 v){
	return this;
}
LegoMan* LegoMan::rotate(vec3 v){
	return this;
}

LegoMan* LegoMan::reflash(){
	drawLegoMan();
	return this;
}
LegoMan* LegoMan::reset(){
	return this;
}	

LegoMan::~LegoMan(){

}