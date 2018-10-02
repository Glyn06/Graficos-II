#pragma once

#if QUINTANAENGINE_EXPORTS
#define QUINTANAENGINE_API __declspec(dllexport)
#else
#define QUINTANAENGINE_API __declspec(dllimport)
#endif