#property copyright "Copyright 2014, micclly."
#property link      "https://micclly.info"
#property strict
#property show_inputs

input string i_subject = "Test"; // Mail Subject
input string i_body = "From MT4"; // Mail Body

void OnStart()
{
    SendMail(i_subject, i_body);
}
