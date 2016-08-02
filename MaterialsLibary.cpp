#include "MaterialsLibary.h"

/*
 *Implement 24 materials type. Functon getMaterial do this what has in name....
 *Valuses of materials are from "..."
*/

using namespace PolyReductor;
using namespace Renderer;

Material materialTable[MaterialType::NUMBER_OF_MATERIALS_TYPE] = 
{
	{ glm::vec3(0.0215,0.1745,0.215),glm::vec3(0.07658,0.61424,0.7568),glm::vec3(0.633,0.72811,0.633),0.6 },//emerald
	{ glm::vec3(0.135,0.2225,0.1575),glm::vec3(0.54,0.89,0.63),glm::vec3(0.316228,0.316228,0.316228),0.1 },//jade
	{ glm::vec3(0.05375,0.05,0.06625),glm::vec3(0.18275,0.17,0.22525),glm::vec3(0.332471,0.328643,0.346435),0.3 },//obsidian
	{ glm::vec3(0.25,0.20725,0.20725),glm::vec3(1.0,0.829,0.829),glm::vec3(0.296648,0.296648,0.296648),0.088 },//pearl
	{ glm::vec3(0.1745,0.01175,0.01175),glm::vec3(0.61424,0.4136,0.727811),glm::vec3(0.727811,0.626959,0.626959),0.6 },//ruby
	{ glm::vec3(0.1,0.18725,0.1745),glm::vec3(0.396,0.74151,0.69102),glm::vec3(0.297254,0.30829,0.306678),0.1 },//torquoise
	{ glm::vec3(0.329412,0.223529,0.027451),glm::vec3(0.780392,0.568627,0.113725),glm::vec3(0.992157,0.941176,0.807843),0.21794872 },//brass
	{ glm::vec3(0.2125,0.1275,0.054),glm::vec3(0.714,0.4284,0.18144),glm::vec3(0.393548,0.271906,0.166721),0.2},//bronze
	{ glm::vec3(0.25,0.25,0.25),glm::vec3(0.4,0.4,0.4),glm::vec3(0.774597,0.774597,0.774597),0.6 },//chrome
	{ glm::vec3(0.19125,0.0735,0.0225),glm::vec3(0.7038,0.27048,0.0828),glm::vec3(0.256777,0.137622,0.086014),0.1 },//copper
	{ glm::vec3(0.24725,0.1995,0.0745),glm::vec3(0.75164,0.60648,0.22648),glm::vec3(0.628281,0.555802,0.366065),0.4 },//gold
	{ glm::vec3(0.19225,0.19225,0.19225),glm::vec3(0.19225,0.19225,0.19225),glm::vec3(0.508273,0.508273,0.508273),0.4 },//silver
	{ glm::vec3(0.0,0.0,0.0),glm::vec3(0.01,0.01,0.01),glm::vec3(0.50,0.50,0.50),0.25 },//black plastic
	{ glm::vec3(0.0,0.1,0.06),glm::vec3(0.0,0.50980392,0.50980392),glm::vec3(0.50196078,0.50196078,0.50196078),0.25 },//cyan plastic
	{ glm::vec3(0.0,0.0,0.0),glm::vec3(0.1,0.35,0.1),glm::vec3(0.45,0.55,0.45),0.25 },//green plastic
	{ glm::vec3(0.0,0.0,0.0),glm::vec3(0.5,0.0,0.0),glm::vec3(0.7,0.6,0.6),0.25 },//red plastic
	{ glm::vec3(0.0,0.0,0.0),glm::vec3(0.55,0.55,0.55),glm::vec3(0.7,0.70,0.70),0.25 },//white plastic
	{ glm::vec3(0.0,0.0,0.0),glm::vec3(0.5,0.5,0.0),glm::vec3(0.6,0.6,0.5),0.25 },//yellow plastic
	{ glm::vec3(0.02,0.02,0.02),glm::vec3(0.01,0.01,0.01),glm::vec3(0.4,0.4,0.4),0.078125 },//black rubber
	{ glm::vec3(0.0,0.05,0.05),glm::vec3(0.4,0.5,0.5),glm::vec3(0.04,0.7,0.7),0.078125 },//cyan rubber
	{ glm::vec3(0.0,0.05,0.0),glm::vec3(0.4,0.5,0.4),glm::vec3(0.04,0.7,0.04),0.078125 },//green rubber
	{ glm::vec3(0.05,0.0,0.0),glm::vec3(0.5,0.4,0.4),glm::vec3(0.7,0.04,0.04),0.078125 },//red rubber
	{ glm::vec3(0.05,0.05,0.05),glm::vec3(0.5,0.5,0.5),glm::vec3(0.7,0.7,0.7),0.078125 },//white rubber
	{ glm::vec3(0.05,0.05,0.0),glm::vec3(0.5,0.5,0.4),glm::vec3(0.7,0.7,0.04),0.078125 }//yellow rubber
};


Material PolyReductor::Renderer::getMaterial(MaterialType type)
{
	return materialTable[static_cast<int>(type)];
}
