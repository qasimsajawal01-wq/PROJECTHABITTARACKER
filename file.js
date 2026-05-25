const STORAGE_KEY = 'habit-tracker-habits';

const habitInput = document.getElementById('habit-input');
const addBtn = document.getElementById('add-btn');
const habitList = document.getElementById('habit-list');
const emptyState = document.getElementById('empty-state');
const progressSection = document.getElementById('progress-section');
const progressBar = document.getElementById('progress-bar');
const progressBarWrap = document.getElementById('progress-bar-wrap');
const progressLabel = document.getElementById('progress-label');

// ─── Data ───────────────────────────────────────────────────

function loadHabits() {
  try {
    return JSON.parse(localStorage.getItem(STORAGE_KEY)) || [];
  } catch {
    return [];
  }
}

function saveHabits(habits) {
  localStorage.setItem(STORAGE_KEY, JSON.stringify(habits));
}

// ─── Render ─────────────────────────────────────────────────

function render(habits) {
  habitList.innerHTML = '';

  const completed = habits.filter(h => h.done).length;
  const total = habits.length;
  const pct = total === 0 ? 0 : Math.round((completed / total) * 100);

  // Progress section
  if (total === 0) {
    progressSection.hidden = true;
    emptyState.hidden = false;
  } else {
    progressSection.hidden = false;
    emptyState.hidden = true;
    progressBar.style.width = pct + '%';
    progressBarWrap.setAttribute('aria-valuenow', pct);
    progressLabel.textContent = `${completed} / ${total} completed`;
  }

  // Habit items
  habits.forEach(habit => {
    const li = document.createElement('li');
    li.className = 'habit-item' + (habit.done ? ' completed' : '');
    li.dataset.id = habit.id;

    const checkbox = document.createElement('input');
    checkbox.type = 'checkbox';
    checkbox.className = 'habit-item__checkbox';
    checkbox.checked = habit.done;
    checkbox.id = 'habit-' + habit.id;
    checkbox.setAttribute('aria-label', 'Mark "' + habit.name + '" as ' + (habit.done ? 'incomplete' : 'complete'));

    const label = document.createElement('label');
    label.className = 'habit-item__label';
    label.htmlFor = 'habit-' + habit.id;
    label.textContent = habit.name;

    const deleteBtn = document.createElement('button');
    deleteBtn.className = 'btn btn--danger';
    deleteBtn.setAttribute('aria-label', 'Delete habit: ' + habit.name);
    deleteBtn.innerHTML = `
      <svg width="16" height="16" viewBox="0 0 24 24" fill="none" stroke="currentColor" stroke-width="2" stroke-linecap="round" stroke-linejoin="round" aria-hidden="true">
        <polyline points="3 6 5 6 21 6"></polyline>
        <path d="M19 6l-1 14H6L5 6"></path>
        <path d="M10 11v6M14 11v6"></path>
        <path d="M9 6V4h6v2"></path>
      </svg>`;

    checkbox.addEventListener('change', () => toggleHabit(habit.id));
    deleteBtn.addEventListener('click', () => deleteHabit(habit.id, li));

    li.appendChild(checkbox);
    li.appendChild(label);
    li.appendChild(deleteBtn);
    habitList.appendChild(li);
  });
}

// ─── Actions ────────────────────────────────────────────────

function addHabit() {
  const name = habitInput.value.trim();
  if (!name) {
    habitInput.focus();
    return;
  }

  const habits = loadHabits();
  habits.push({ id: Date.now(), name, done: false });
  saveHabits(habits);
  habitInput.value = '';
  render(habits);
}

function toggleHabit(id) {
  const habits = loadHabits().map(h =>
    h.id === id ? { ...h, done: !h.done } : h
  );
  saveHabits(habits);
  render(habits);
}

function deleteHabit(id, li) {
  li.classList.add('removing');
  li.addEventListener('animationend', () => {
    const habits = loadHabits().filter(h => h.id !== id);
    saveHabits(habits);
    render(habits);
  }, { once: true });
}

// ─── Events ─────────────────────────────────────────────────

addBtn.addEventListener('click', addHabit);

habitInput.addEventListener('keydown', e => {
  if (e.key === 'Enter') addHabit();
});

// ─── Init ────────────────────────────────────────────────────

render(loadHabits());
