#pragma once

#ifdef CONTROLS_API
#define CONTROLS_EXPORT __declspec(dllexport)
#else
#define CONTROLS_EXPORT __declspec(dllimport)
#endif


