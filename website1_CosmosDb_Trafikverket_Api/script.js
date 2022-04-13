let temp2 = document.getElementById('temp2')
let date2 = document.getElementById('date2')
let time2 = document.getElementById('time2')

let temp1 = document.getElementById('temp1')
let date1 = document.getElementById('date1')
let time1 = document.getElementById('time1')

let unixTimestamp;
let tempslice;
let unixTimestamp1;
let tempslice1;

fetch(" http://localhost:7071/api/getAllFromCosmos")
.then(res => res.json())
.then(data => {
    console.log(data)
    tempslice =data[data.length-1].data.Measurement.Air.Temp
    let  strTemp = JSON.stringify(tempslice).slice(0,3)
    temp1.innerHTML = strTemp
    unixTimestamp = data[data.length-1]._ts
    let milliseconds = unixTimestamp * 1000
    let dateObject = new Date(milliseconds)
    date1.innerHTML = dateObject.getDate() + '-' + (dateObject.getMonth()+1) + '-' + dateObject.getFullYear()
    time1.innerHTML = dateObject.getHours() + ':' + (dateObject.getMinutes()<10?'0':'') + dateObject.getMinutes()
    
}).catch(err => { console.error(err) })



fetch(" http://localhost:7071/api/getAllFromCosmosBme")
.then(res => res.json())
.then(dataa => {
    console.log(dataa)
    tempslice =dataa[dataa.length-1].temp
    let  strTemp = JSON.stringify(tempslice).slice(0,3)
    temp2.innerHTML = strTemp
    unixTimestamp1 = dataa[dataa.length-1].ts
    let milliseconds = unixTimestamp1 * 1000
    let dateObject = new Date(milliseconds)
    date2.innerHTML = dateObject.getDate() + '-' + (dateObject.getMonth()+1) + '-' + dateObject.getFullYear()
    time2.innerHTML = dateObject.getHours() + ':' + (dateObject.getMinutes()<10?'0':'') + dateObject.getMinutes()
    
}).catch(err => { console.error(err) })