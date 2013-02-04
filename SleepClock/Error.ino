void Error(const char *msg) {
  Send32Zero();
  DataDealWithAndSend(0, 255, 255);
  Send32Zero(); 
}

