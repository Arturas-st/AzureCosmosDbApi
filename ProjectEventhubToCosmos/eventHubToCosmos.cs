using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using Microsoft.Azure.EventHubs;
using Microsoft.Azure.WebJobs;
using Microsoft.Extensions.Logging;
using Newtonsoft.Json;

namespace ProjectEventhubToCosmos
{
    public static class eventHubToCosmos
    {
        [FunctionName("eventHubToCosmos")]
        public static void Run(
            [EventHubTrigger("bme280hub", Connection = "eventhubcon")] EventData events,
             [CosmosDB(
                databaseName: "IOT2020",
                collectionName: "Messagesss",
                CreateIfNotExists = true,
                ConnectionStringSetting = "cosmosDbConnection"

            )]out dynamic cosmos,
            ILogger log)

        {
            try
            {
                var msg = JsonConvert.DeserializeObject<DhtMeasurement>(Encoding.UTF8.GetString(events.Body.ToArray()));
                msg.deviceId = events.SystemProperties["iothub-connection-device-id"].ToString();
                msg.School = events.Properties["School"].ToString();
                msg.Name = events.Properties["Name"].ToString();
                msg.type = events.Properties["type"].ToString();


                var json = JsonConvert.SerializeObject(msg);
                cosmos = json;
                log.LogInformation($"Measurement was saved to Cosmos DB, Message::{json}");

            }
            catch (Exception e)
            {
                cosmos = null;
                log.LogInformation($"Unable to process Request, Error::{e.Message}");


            }

        }
    }
}
