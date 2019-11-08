#include <stdio.h>                                                                                   
#include <stdlib.h>                                                                                  
#include <mysql.h>                                                                             

int main(void)                                                                                       
{                                                                                                    
  MYSQL *conn;                                                                                       

  if ((conn = mysql_init(NULL)) == NULL)                                                             
  {                                                                                                  
    fprintf(stderr, "Could not init DB\n");                                                 
    return EXIT_FAILURE;                                                                             
  }                                                                                                  
  if (mysql_real_connect(conn, "localhost", "root", "Joker&1433", "test", 0, NULL, 0) == NULL)             
  {                                                                                                  
    fprintf(stderr, "DB Connection Error\n");                                                        
    return EXIT_FAILURE;                                                                             
  }                                                                                                  
  if (mysql_query(conn, "INSERT INTO table_1 (test) VALUES ('Hello World')") != 0)                   
  {                                                                                                  
    fprintf(stderr, "Query Failure\n");                                                              
    return EXIT_FAILURE;                                                                             
  }                                                                                                  
  mysql_close(conn);                                                                                 
  return EXIT_SUCCESS;                                                                               
}