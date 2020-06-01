#pragma once

#ifdef VIEWS_API
#define VIEWS_EXPORT __declspec(dllexport)
#else
#define VIEWS_EXPORT __declspec(dllimport)
#endif