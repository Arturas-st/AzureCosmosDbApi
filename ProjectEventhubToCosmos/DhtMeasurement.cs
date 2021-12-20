using System;
using System.Collections.Generic;
using System.Text;

namespace ProjectEventhubToCosmos
{
    public class DhtMeasurement
    {
        public string deviceId { get; set; }
        //public string deviceType { get; set; }
        public float temp { get; set; }
        public float hum { get; set; }
        public long ts { get; set; }
        public string id { get; set; }
        public string type { get; set; }
        public string Name { get; set; }
        public string School { get; set; }

    }
}
