using System;
using System.Collections.Generic;
using System.Data.SqlClient;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace DataBase
{
    public class BeerDB : DB
    {
        public BeerDB(string server, string db, string user, string pasword) : base(server, db, user, pasword) { }

        public List<Beer> GetAll()
        {
            Connect();

            List<Beer> beers = new List<Beer>();
            string query = "SELECT ID, Name, BrandID FROM BEER";
            SqlCommand command = new SqlCommand(query, _connection);
            SqlDataReader reader = command.ExecuteReader();

            while (reader.Read())
            {
                int id = reader.GetInt32(0);
                string name = reader.GetString(1);
                int BrandId = reader.GetInt32(2);

                beers.Add(new Beer(id,name, BrandId));
            }

            Close();

            return beers;
        }

        public Beer Get(int id)
        {
            Connect();

            Beer beer = null;

            string query = "SELECT * FROM BEER " +
                "WHERE ID = @id";
            SqlCommand command = new SqlCommand(query, _connection);
            command.Parameters.AddWithValue("@id", id);
            SqlDataReader reader = command.ExecuteReader();

            while (reader.Read())
            {
                string name = reader.GetString(1);
                int BrandId = reader.GetInt32(2);
                beer = new Beer(id, name, BrandId);
            }

            Close();

            return beer;
        }

        public void Add(Beer beer)
        {
            Connect();
            string query = "INSERT INTO Beer(Name, BrandId) " +
                "VALUES(@name, @BrandId)";

            SqlCommand command = new SqlCommand(query,_connection);
            command.Parameters.AddWithValue("@name", beer.Name);
            command.Parameters.AddWithValue("@BrandId", beer.BrandId);
            command.ExecuteNonQuery();

            Close();
        }

        public void Edit(Beer beer) 
        {
            Connect();

            string query = "UPDATE beer SET Name=@name, BrandID=@brandId " +
                "WHERE id=@id";
            SqlCommand command = new SqlCommand(query,_connection);
            command.Parameters.AddWithValue("@name", beer.Name);
            command.Parameters.AddWithValue("@brandId", beer.BrandId);
            command.Parameters.AddWithValue("@id", beer.Id);
            command.ExecuteNonQuery();

            Close();
        }

        public void Delete(int id)
        {
            Connect();

            string query = "DELETE FROM beer WHERE ID=@id";
            SqlCommand command = new SqlCommand(query,_connection);
            command.Parameters.AddWithValue("@id", id);
            command.ExecuteNonQuery();

            Close();
        }
    }
}
