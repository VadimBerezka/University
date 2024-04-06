"use strict"
let Vipadenie = undefined;
let checkk = undefined;
function Vipadeniee(selff) {

  let Vizvala = document.getElementById(selff);
  console.log(checkk)
  console.log(selff)
  if (checkk == selff) {
    if (Vipadenie != undefined) {
      document.body.removeChild(Vipadenie);
      Vipadenie = undefined;
    }
    checkk = undefined;
  }
  else {
    if (Vipadenie != undefined) {
      document.body.removeChild(Vipadenie);
      Vipadenie = undefined;
    }
    Vipadenie = document.createElement('div');
    Vipadenie.textContent = "Выпало";
    checkk = selff;
    let CoordX = Vizvala.offsetLeft;
    let CoordY = Vizvala.offsetTop;
    console.log("Element X: " + CoordX);
    console.log("Element Y: " + CoordY);
    Vipadenie.style.position = 'absolute'
    Vipadenie.style.top = (CoordY + 50 + 'px');
    Vipadenie.style.left = (CoordX + 'px');
    Vipadenie.style.width = '100px';
    Vipadenie.style.height = '50px';
    Vipadenie.style.backgroundColor = ('rgb(100,150,100)');
    Vipadenie.id = 'Aded';
    document.body.appendChild(Vipadenie);
  }
}