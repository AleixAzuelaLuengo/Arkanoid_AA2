#include "Renderer.h"

Renderer::Renderer()
{
	// --- INIT ---
	if (SDL_Init(SDL_INIT_EVERYTHING) != 0) throw "No es pot inicialitzar SDL subsystems";

	// --- WINDOW ---
	m_window = SDL_CreateWindow("SDL...", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, SCREEN_WIDTH, SCREEN_HEIGHT, SDL_WINDOW_SHOWN );
	if (m_window == nullptr) throw "No es pot inicialitzar SDL_Window";

	// --- RENDERER ---
	m_renderer = SDL_CreateRenderer(m_window, -1, SDL_RENDERER_ACCELERATED | SDL_RENDERER_PRESENTVSYNC);
	if (m_renderer == nullptr) throw "No es pot inicialitzar SDL_Renderer";

	//Initialize renderer color
	SDL_SetRenderDrawColor(m_renderer, 255, 255, 255, 255);

	//Initialize PNG loading
	const Uint8 imgFlags{ IMG_INIT_PNG | IMG_INIT_JPG };
	if (!(IMG_Init(imgFlags) & imgFlags)) throw "Error: SDL_imageinit";

	// ---- TTF ----
	if (TTF_Init() != 0) throw"No es pot inicialitzar SDL_ttf";

};


Renderer::~Renderer()
{
	for (auto &t : m_textureData) SDL_DestroyTexture(t.second), t.second = nullptr;
	for (auto &f : m_fontData) TTF_CloseFont(f.second), f.second = nullptr;
	SDL_DestroyRenderer(m_renderer);
	m_renderer = nullptr;
	SDL_DestroyWindow(m_window);
	m_window = nullptr;

	IMG_Quit();
	TTF_Quit();
	SDL_Quit();

};

void Renderer::Clear() { SDL_RenderClear(m_renderer); };

void Renderer::Render() { SDL_RenderPresent(m_renderer); };

void Renderer::LoadFont(Font font) {
	TTF_Font *ttfFont{ TTF_OpenFont(font.path.c_str(), font.size) };
	if (ttfFont == nullptr) throw"No espot inicialitzar TTF_Font";
	m_fontData[font.id] = ttfFont;
};

void Renderer::LoadTexture(const std::string &id, const std::string &path) {
	SDL_Texture *texture{ IMG_LoadTexture(m_renderer, path.c_str()) };
	if (texture == nullptr) throw "No s'han pogut crear les textures";
	m_textureData[id] = texture;
};

void Renderer::LoadTextureText(const std::string &fontId, MyText text) {
	SDL_Surface	*tmpSurf = TTF_RenderText_Blended(m_fontData[fontId], text.text.c_str(), SDL_Color{ text.idColor.r, text.idColor.g, text.idColor.b,text.idColor.a });
	if (tmpSurf == nullptr) throw "Unable to create the SDL text surface";
	SDL_Texture *texture{ SDL_CreateTextureFromSurface(m_renderer, tmpSurf) };
	m_textureData[text.font.id] = texture;
	
};

Vector2 Renderer::GetTextureSize(const std::string &id) {
	int w; int h;
	SDL_QueryTexture(m_textureData[id], NULL, NULL,&w, &h);
	return {w, h};
};

void Renderer::PushImage(const std::string &id, const Rect &rect) {
	SDL_Rect temp = ConvertFromRectToSDL_Rect(rect);
	SDL_RenderCopy(m_renderer, m_textureData[id], nullptr, &temp);
};

void Renderer::PushRotatedImage(const std::string & id, const Rect & rect, float angle)
{
	SDL_Point center = { rect.proportions.x / 2, rect.proportions.y / 2 };
	SDL_Rect temp = ConvertFromRectToSDL_Rect(rect);
	SDL_RenderCopyEx(m_renderer, m_textureData[id], nullptr, &temp, angle, &center, SDL_FLIP_NONE);
};

void Renderer::PushSprite(const std::string &id, const Rect &rectSprite,const Rect &rectPos) {
	SDL_Rect temp = ConvertFromRectToSDL_Rect(rectSprite);
	SDL_Rect temp2 = ConvertFromRectToSDL_Rect(rectPos);
	SDL_RenderCopy(m_renderer, m_textureData[id], &temp, &temp2);
}

void Renderer::PushRotatedSprite(const std::string & id, const Rect & rectSprite, const Rect & rectPos, float angle){
	SDL_Point center = { rectPos.proportions.x / 2, rectPos.proportions.y / 2 };
	SDL_Rect temp = ConvertFromRectToSDL_Rect(rectSprite);
	SDL_Rect temp2 = ConvertFromRectToSDL_Rect(rectPos);
	SDL_RenderCopyEx(m_renderer, m_textureData[id], &temp, &temp2, angle, &center, SDL_FLIP_NONE);
}

void Renderer::SetRendreDrawColor(int r, int g, int b)
{
	SDL_SetRenderDrawColor(m_renderer, r, g, b, 255);
}

SDL_Rect Renderer::ConvertFromRectToSDL_Rect(Rect rect)
{
	SDL_Rect temp;
	temp.h = rect.proportions.y;
	temp.w = rect.proportions.x;
	temp.x = rect.position.x;
	temp.y = rect.position.y;
	return temp;
}



Renderer* Renderer::renderer = nullptr;
