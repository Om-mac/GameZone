async function playGame(gameName) {
  document.getElementById("outputArea").innerText = `Running ${gameName}...\nPlease wait...`;

  try {
    const res = await fetch("/run_game", {
      method: "POST",
      headers: { "Content-Type": "application/json" },
      body: JSON.stringify({ game: gameName })
    });

    const data = await res.json();
    document.getElementById("outputArea").innerText = data.output;
  } catch (err) {
    document.getElementById("outputArea").innerText = "⚠️ Error running game!";
  }
}
