// Copyright 2017 Bevzuk Semen

#ifndef MODULES_VECTOR3D_INCLUDE_VECTOR3D_APP_H_
#define MODULES_VECTOR3D_INCLUDE_VECTOR3D_APP_H_

#include <string>

class Vector3DApp {
 public:
     Vector3DApp();
     std::string operator()(int argc, const char** argv);

 private:
     void Help(const char* appname, const char* message = "");
     bool ValidateNumberOfArguments(int argc, const char** argv);
     std::string message_;
     typedef struct {
        double v1_x;
        double v1_y;
        double v1_z;
        double v2_x;
        double v2_y;
        double v2_z;
        char operation;
     } ArgumentsBinary;
     typedef struct {
         double v1_x;
         double v1_y;
         double v1_z;
         char operation;
     } ArgumentsUnary;
};

#endif  // MODULES_VECTOR3D_INCLUDE_VECTOR3D_APP_H_
