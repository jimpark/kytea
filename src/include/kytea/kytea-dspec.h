/*
* Copyright 2009-2016, KyTea Development Team
* 
* Licensed under the Apache License, Version 2.0 (the "License");
* you may not use this file except in compliance with the License.
* You may obtain a copy of the License at
* 
*     http://www.apache.org/licenses/LICENSE-2.0
* 
* Unless required by applicable law or agreed to in writing, software
* distributed under the License is distributed on an "AS IS" BASIS,
* WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
* See the License for the specific language governing permissions and
* limitations under the License.
*/

#ifndef KYTEA_DSPEC_H__
#define KYTEA_DSPEC_H__
// Generic helper definitions for shared library support
#if defined _WIN32 || defined __CYGWIN__
	#define KYTEA_HELPER_DLL_IMPORT __declspec(dllimport)
	#define KYTEA_HELPER_DLL_EXPORT __declspec(dllexport)
	#define KYTEA_HELPER_DLL_LOCAL
#else
	#if __GNUC__ >= 4
		#define KYTEA_HELPER_DLL_IMPORT __attribute__ ((visibility ("default")))
		#define KYTEA_HELPER_DLL_EXPORT __attribute__ ((visibility ("default")))
		#define KYTEA_HELPER_DLL_LOCAL  __attribute__ ((visibility ("hidden")))
	#else
		#define KYTEA_HELPER_DLL_IMPORT
		#define KYTEA_HELPER_DLL_EXPORT
		#define KYTEA_HELPER_DLL_LOCAL
	#endif
#endif

// Now we use the generic helper definitions above to define KYTEA_API and KYTEA_LOCAL.
// KYTEA_API is used for the public API symbols. It either DLL imports or DLL exports (or does nothing for static build)
// KYTEA_LOCAL is used for non-api symbols.

#ifdef KYTEA_DLL // defined if the package is compiled as a DLL
	#ifdef KYTEA_DLL_EXPORTS // defined if we are building the the package as a DLL (instead of using it)
		#define KYTEA_API KYTEA_HELPER_DLL_EXPORT
	#else
		#define KYTEA_API KYTEA_HELPER_DLL_IMPORT
	#endif // KYTEA_DLL_EXPORTS
	#define KYTEA_LOCAL KYTEA_HELPER_DLL_LOCAL
#else // KYTEA_DLL is not defined: this means the package is a static lib.
	#define KYTEA_API
	#define KYTEA_LOCAL
#endif // KYTEA_DLL

#endif //KYTEA_DSPEC_H__
