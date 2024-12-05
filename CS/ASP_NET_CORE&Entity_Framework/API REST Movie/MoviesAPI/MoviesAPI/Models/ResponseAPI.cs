using System.Net;

namespace MoviesAPI.Models
{
    public class ResponseAPI
    {
        public ResponseAPI()
        {
            ErrorMessage = new List<string>();
        }

        public HttpStatusCode StatusCode { get; set; }
        public bool IsSuccess { get; set; } = true;
        public List<string> ErrorMessage { get; set; }
        public object Result { get; set; }
    }
}
