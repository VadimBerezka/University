window.addEventListener("load", () => {
  sessionStorage.IsThisFirstTime_Log_From_LiveServer ? sessionStorage.removeItem("IsThisFirstTime_Log_From_LiveServer") : (null)
})

const navLink = document.querySelectorAll(".nav-link");

navLink.forEach((link) => {
  link.addEventListener("mouseover", () => {
    link.style.transform = "scale(1.1)";
  });

  link.addEventListener("mouseout", () => {
    link.style.transform = "scale(1)";
  });
});

const buttons = document.querySelectorAll(".game-link, .footer-link");

buttons.forEach((button) => {
  button.addEventListener("mouseover", () => {
    button.style.transform = "scale(1.1)";
  });

  button.addEventListener("mouseout", () => {
    button.style.transform = "scale(1)";
  });
});

function deleteFromBean(str, event) {

  for (; str < sessionStorage.length / 3; str++) {
    sessionStorage.setItem(`${str}name`, sessionStorage[`${str + 1}name`])
  }
  sessionStorage.removeItem(`${str}name`)
  sessionStorage.removeItem(`${str}price`)
  sessionStorage.removeItem(`${str}picture`)
}

function addToBean(event) {
  let arr = document.getElementsByTagName("lord-icon");
  let index;
  for (let i = 0; i < arr.length; i++) {
    if (arr[i] === event.target) {
      index = i - 1;
    }
  }

  let name = document.getElementsByClassName("game-title")[index].innerHTML;
  let price = document.getElementsByClassName("price")[index].innerHTML;
  let picture = document.getElementsByClassName("game-image")[index].src;

  let flag = true,
    str;
  for (let i = 0; i < sessionStorage.length; i++) {
    str = i;
    if (sessionStorage[`${str}name`] === name) {
      alert("Товар удален из корзины");
      deleteFromBean(str);
      return;
    }
  }
  if (flag) {
    let leng = sessionStorage.length / 3 + 1;
    sessionStorage.setItem(`${leng}name`, name);
    sessionStorage.setItem(`${leng}price`, price);
    sessionStorage.setItem(`${leng}picture`, picture);
  }
}


const genge = document.querySelectorAll('.genge')

genge.forEach(link => {
  link.addEventListener('mouseover', () => {
    link.style.transform = 'scale(1.1)'
  })

  link.addEventListener('mouseout', () => {
    link.style.transform = 'scale(1)'
  })
})




