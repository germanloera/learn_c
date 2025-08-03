
#ifndef STUDENT_UI
#define STUDENT_UI


class StudentFrame {

public:
    float numero_decimal = 0.0f;
     int numero_entero = 0;
     char texto1[256] = "";
     char texto2[256] = "";
     int radio_selection = 0;

     void addStudentFrame();
     void studentListTable();
     void controlsGroup();

  
};



#endif