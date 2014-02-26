/* Example structure for gyroscope data.
 * Note that both sides of the communication need to have
 * the struct defined the same; if not variable names then
 * at least correctly-typed members.
 */
 
typedef struct
{
  float x_angle; //Roll
  float y_angle; //Pitch
  float z_angle; //Yaw
} gyroData;

/* To use this function, first define and populate a struct
 * to send. Then call the function like so:
 * structSend(&myStruct, sizeof(type_of_myStruct);
 * for example:
 *
 * typedef struct
 * {
 *   char firstChar;
 *   char secondChar;
 * } charStruct;
 * 
 * charStruct myStruct;
 *
 * myStruct.firstChar = 'a';
 * myStruct.secondChar = 'b';
 *
 * structSend(&myStruct, sizeof(charStruct));
 */
 
 void structSend(void *message, int length)
{
  uint8_t *pointer = (uint8_t*)message;
  for(int i = 0; i < length; i++)
  {
    Serial.write(*(pointer+i));
  }
}

/* To use this function, it's much the same as above:
 * Define a struct, which must have the same members as the
 * struct you're sending, then when you have serial data
 * available call this function and pass it an initialised
 * structure to write into.
 */
 
void receiveStruct(void *bufferStruct, int length)
{
  uint8_t *pointer = (uint8_t*)bufferStruct;
  for(int i = 0; i < length; i++)
  {
    *(pointer+i) = StructSerial.read();
    while(!Serial.available());
  }
}
