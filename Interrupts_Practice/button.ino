/**/
void button_Push()
{  
  //Read in the blue button
  if ((digitalRead(4) ==1)  && (pressed == 0))
  {
    pressed = 1;
    mtrPwr = 255;
  }
  else if ((digitalRead(4) ==1)  && (pressed == 1))
  {
    pressed = 0;
    mtrPwr = 0;
  }
}



// int buttonMotor() 
// {
//   float x = 20; 
//   if (pressed == 1)
//   {
//     //motor1(7,pressed,9,70);
//     //x =rotA(y);
//     return x;
//   } 
//   else 
// //  x = rotA();
//   //motor1(7,y,9,0);
//   return x;
// }
