"use strict"

function Drop() { 
    console.log("Starting movement"); 
    let shouldMove = true; 
 
    let elem = document.getElementById(event.target.id); 
 
    let shiftX = event.pageX - elem.getBoundingClientRect().left - scrollX; 
    let shiftY = event.pageY - elem.getBoundingClientRect().top - scrollY; 
 
    document.onmousemove = function(event) { 
        if (shouldMove) { 
            console.log("Movement"); 
            elem.style.left = event.pageX - shiftX + 'px'; 
            elem.style.top = event.pageY - shiftY + 'px'; 
        } 
    } 
 
    document.onmouseup = function() { 
        console.log("Finishing movement"); 
        shouldMove = false; 
    } 
 
    elem.ondragstart = function() { 
        return false; 
    } 
 
    elem.ondragend = function() { 
        return false; 
    } 
 
}

const img1 = document.getElementById("image2")
let flag1 = true
let i = 0
setInterval("lineMove()", 10)

function lineMove(){
	if(flag1){
		i=i+10
		if(i > 1200)flag1 = false
	}
    else{
		i=i-10
		if(i == 0)flag1 = true
	}

	img1.style.left = i + "px"
}

const img2 = document.getElementById('image3')
let flag2 = true
let num = 0
let coordinateX = 0,coordinateY = 0
setInterval("curveMove()", 100)

function curveMove(){
	if(flag2){
		num++
		if(num > 400)flag2 = false
	}else{
		num--
		if(num == 0)flag2 = true
	}
	img2.style.left = (num * 3) + "px"
	img2.style.top = Math.cos(num)*40 + "px"
}
