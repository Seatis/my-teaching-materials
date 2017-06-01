/*

    int enum_port = comEnumerate();
    int port = comFindPort("COM30");

    printf("%d\n", port);
    if (comOpen(port, 115200) == 0) {
        printf("Error opening port.\n");
        return -1;
    }

    char buff[512];
    while (1)
    {
        int bytes = comRead(port, buff, 511);
        if (bytes > 0) {
            buff[bytes] = '\0';
            printf("%s", buff);
        }
    }
    comClose(port);

    */
