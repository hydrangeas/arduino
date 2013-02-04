// connect to digital 0,1
int Clkpin = 15;
int Datapin = 14;

void ClkProduce(void)
{
  digitalWrite(Clkpin, LOW);
  delayMicroseconds(20); 
  digitalWrite(Clkpin, HIGH);
  delayMicroseconds(20);   
}

void Send32Zero(void)
{
  unsigned char i;

  for (i=0; i<32; i++)
  {
    digitalWrite(Datapin, LOW);
    ClkProduce();
  }
}

uint8 TakeAntiCode(uint8 dat)
{
  uint8 tmp = 0;

  if ((dat & 0x80) == 0)
  {
    tmp |= 0x02; 
  }

  if ((dat & 0x40) == 0)
  {
    tmp |= 0x01; 
  }

  return tmp;
}

// gray data
void DatSend(uint32 dx)
{
  uint8 i;

  for (i=0; i<32; i++)
  {
    if ((dx & 0x80000000) != 0)
    {
      digitalWrite(Datapin, HIGH);
    }
    else
    {
      digitalWrite(Datapin, LOW);
    }

    dx <<= 1;
    ClkProduce();
  }
}

// data processing
void DataDealWithAndSend(uint8 r, uint8 g, uint8 b)
{
  uint32 dx = 0;

  dx |= (uint32)0x03 << 30;             // highest two bits 1，flag bits
  dx |= (uint32)TakeAntiCode(b) << 28;
  dx |= (uint32)TakeAntiCode(g) << 26;	
  dx |= (uint32)TakeAntiCode(r) << 24;

  dx |= (uint32)b << 16;
  dx |= (uint32)g << 8;
  dx |= r;

  DatSend(dx);
}

void ledSetup()  { 
  pinMode(Datapin, OUTPUT);
  pinMode(Clkpin, OUTPUT);

  Send32Zero();
  DataDealWithAndSend(255, 0, 255);
  Send32Zero(); 
} 

void illuminateLed(int value) {
  if(value==1) {
    Send32Zero(); // begin
    DataDealWithAndSend(255, 0, 0); // first node data
    Send32Zero();  // send to update data    
  } 
  else {
    Send32Zero();
    DataDealWithAndSend(0, 255, 0);
    Send32Zero(); 
  }
}



