﻿namespace MoviesAPI.Models.DTOs
{
    public class UserLogingResponseDTO
    {
        public User User { get; set; } 
        public string Role { get; set; }
        public  string Token { get; set; }
    }
}