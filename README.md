# AvnApplication
Currently, App need to get data list from service at the first time.\
So please follow steps below:\
Precondition:\
Config service: add #ifdef TEST_MQ, TEST_WAIT_RECV_MSG, TEST_WRITE_SHM, TEST_READ_SHM, TEST_ACK\
Step 1. Run service\
Step 2. Run app
