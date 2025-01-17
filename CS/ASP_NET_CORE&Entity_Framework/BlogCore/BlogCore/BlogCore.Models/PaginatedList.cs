﻿using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace BlogCore.Models
{
    public class PaginatedList<T> : List<T>
    {
        public int PageIndex { get; private set; }
        public int TotalPages { get; private set; }
        public string SearchString { get; private set; }

        public PaginatedList(List<T> items, int articlesCount, int pageIndex, int pageSize, string searchString)
        {
            PageIndex = PageIndex;
            TotalPages = (int)Math.Ceiling(articlesCount / (double)pageSize);
            SearchString = searchString;

            AddRange(items);
        }

        public bool HasPreviousPage => (PageIndex > 1);
        public bool HasNextPage => (PageIndex < TotalPages);
    }
}
