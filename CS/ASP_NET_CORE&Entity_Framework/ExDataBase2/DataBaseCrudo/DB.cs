using System;
using System.Collections.Generic;
using System.Data.SqlClient;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace DataBase2
{
    public abstract class DB
    {
        private string _connectionString;
        protected SqlConnection _connection;

        public DB(string server, string db, string user, string pasword)
        {
            _connectionString = $"Data Source={server}; Initial Catalog={db};" +
                $"User={user}; Password={pasword}";
        }

        public void Connect()
        {
            _connection = new SqlConnection(_connectionString);
            _connection.Open();
        }

        public void Close()
        {
            if(_connection != null && _connection.State == System.Data.ConnectionState.Open)
            {
                _connection.Close();
            }
        }
    }
}
