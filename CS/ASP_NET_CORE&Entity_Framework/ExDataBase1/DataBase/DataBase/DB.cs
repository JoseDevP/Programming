using System;
using System.Collections.Generic;
using System.Data.SqlClient;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace DataBase
{
    public abstract class DB
    {
        private string _connecttionString;
        protected SqlConnection _connection;

        public DB(string server, string db, string user, string pasword)
        {
            _connecttionString = $"Data Source={server}; Initial Catalog={db};" +
                $"User={user}; Password={pasword}";
            //_connecttionString = $"Data Source={server}; Initial Catalog={db}; Integrated Security=True;";

        }

        public void Connect()
        {
            _connection = new SqlConnection(_connecttionString);
            _connection.Open();
        }

        public void Close()
        {
            if (_connection != null && _connection.State == System.Data.ConnectionState.Open) 
                _connection.Close();
            
        }
    }
}
