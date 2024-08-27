// script.js

window.onscroll = function() {makeSticky()};

var overlayDiv = document.getElementById("overlay-div");
var sticky = overlayDiv.offsetTop;

function makeSticky() {
  if (window.pageYOffset >= sticky) {
    overlayDiv.classList.add("sticky")
  } else {
    overlayDiv.classList.remove("sticky");
  }
}

const colorDivs = document.querySelectorAll('.colour_choose');
const colorNames = document.querySelectorAll('.name_car p');

colorDivs.forEach(div => {
    div.addEventListener('click', function() {
        // Hide all color names
        colorNames.forEach(name => {
            name.style.display = 'none';
        });

        // Show the selected color's name
        const colorClass = this.getAttribute('data-colour');
        document.querySelector(`.${colorClass}`).style.display = 'block';
    });
});
let index = 0;

const images = document.querySelectorAll('.carousel-images img');
const dots = document.querySelectorAll('.dot');

function showSlide(n) {
    if (n >= images.length) index = 0;
    if (n < 0) index = images.length - 1;

    images.forEach((img, i) => {
        img.classList.remove('active');
        dots[i].classList.remove('active');
    });

    images[index].classList.add('active');
    dots[index].classList.add('active');
}

function nextSlide() {
    index++;
    showSlide(index);
}

function prevSlide() {
    index--;
    showSlide(index);
}

document.getElementById('nextBtn').addEventListener('click', nextSlide);
document.getElementById('prevBtn').addEventListener('click', prevSlide);

// Remove or comment out the auto-slide functionality
// setInterval(nextSlide, 3000);

// Handle dot clicks
dots.forEach((dot, i) => {
    dot.addEventListener('click', () => {
        index = i;
        showSlide(index);
    });
});
