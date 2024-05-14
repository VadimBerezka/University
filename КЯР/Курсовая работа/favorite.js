
window.addEventListener("load", () => {
  sessionStorage.IsThisFirstTime_Log_From_LiveServer ? sessionStorage.removeItem("IsThisFirstTime_Log_From_LiveServer") : (null)

  let temp = [];
  let name, price, picture, item;
  for (let i = 1; i < sessionStorage.length; i = i + 3) {
    if (i == 1) {
      name = sessionStorage.getItem(`${i}name`);
      price = sessionStorage.getItem(`${i}price`);
      picture = sessionStorage.getItem(`${i}picture`);
    } else {
      name = sessionStorage.getItem(`${parseInt(i + 2) / 3}name`);
      price = sessionStorage.getItem(`${parseInt(i + 2) / 3}price`);
      picture = sessionStorage.getItem(`${parseInt(i + 2) / 3}picture`);
    }
    item = { name: name, price: price, picture: picture };
    temp.push(item);
  }

  const main = document.querySelector("main");

  temp.forEach((item) => {
    const node = document.createElement("div");
    node.classList.add("game-container");

    const imageContainer = document.createElement("div");
    imageContainer.classList.add("game-image");
    const image = document.createElement("img");
    image.src = item.picture;
    imageContainer.appendChild(image);
    node.appendChild(imageContainer);

    const heart = document.createElement("div");
    heart.classList.add("del")
    heart.addEventListener("click", deleteFromBean)
    heart.innerHTML = "x"

    node.appendChild(heart);

    const name = document.createElement("h2");
    name.classList.add("game-title");
    name.textContent = item.name;
    node.appendChild(name);

    const price = document.createElement("div");
    price.classList.add("price");
    price.textContent = item.price;
    node.appendChild(price);

    main.appendChild(node);
  });
});

let delButtons = Array.from(document.getElementsByClassName("del"))
delButtons.forEach((button) => { button.addEventListener('click', deleteFromBean) })


function deleteFromBean(event) {
  let arr = document.getElementsByClassName("del");
  let index;
  for (let i = 0; i < arr.length; i++) {
    if (arr[i] === event.target) {
      index = i;
    }
  }

  let name = document.getElementsByClassName("game-title")[index].innerHTML;

  let gamesContainersArray = Array.from(document.getElementsByClassName("game-container"));
  let gamesArray = Array.from(document.getElementsByClassName("game-title"));
  console.log(gamesArray)
  let deleteIndex;
  for (let i = 0; i < gamesArray.length; i++) {
    if (gamesArray[i].innerHTML === name) {
      deleteIndex = i;
      console.log(gamesArray[i].innerHTML)
    }
  }
  console.log(name)
  console.log(deleteIndex)
  console.log(gamesContainersArray)
  gamesContainersArray[deleteIndex].parentNode.removeChild(gamesContainersArray[deleteIndex])
  let str;
  for (let i = 0; i < sessionStorage.length; i++) {
    str = i;
    if (sessionStorage[`${str}name`] === name) {
      break;
    }
  }

  console.log(str)
  for (; str < sessionStorage.length / 3; str++) {
    sessionStorage.setItem(`${str}name`, sessionStorage[`${str + 1}name`])
  }
  sessionStorage.removeItem(`${str}name`)
  sessionStorage.removeItem(`${str}price`)
  sessionStorage.removeItem(`${str}picture`)
}
